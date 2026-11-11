#include<bits/stdc++.h>
using namespace std;
long long a[500003];
long long d[500003];
long long p[500003];
int n,m;
bool checka(){
    bool f=true;
    for(int i=2;i<=n;i++){
        if(d[i]!=0){f=false;break;}
    }
    return f;
}
bool checkb(){
    bool f=true;
    for(int i=3;i<=n;i++){
        if(d[i]!=d[i-1]){f=false;break;}
    }
    return f;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        d[i]=a[i]-a[i-1];

    long long mx=0;
    if(n<=10000){//On2
        for(int h=1;h<n;h++){
            memset(p,0,sizeof p);
            for(int i=h+1;i<=n;i++)
                p[i]=p[i-1]+(i-h)*d[i];
            mx=max((long long)(upper_bound(p+1,p+n+1,m)-p-h),mx);
        }
    }else{
        bool sa=checka();//a
        bool sb=checkb();//b
        if(sa==true)mx=n;
        else if(sb==true){
            for(int i=1;i<=n;i++)
                p[i]=p[i-1]+(i-1)*d[i];
            mx=max((long long)(upper_bound(p+1,p+n+1,m)-p-1),mx);
        }else{//!a!b
            int ww=sqrt(n);
            for(int h=1;h<=ww;h++){
                memset(p,0,sizeof p);
                for(int i=h+1;i<=n;i++)
                    p[i]=p[i-1]+(i-h)*d[i];
                mx=max((long long)(upper_bound(p+1,p+n+1,m)-p-h),mx);
            }
        }
    }

    cout<<mx;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
