#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long a[20000],n,cnt=0,x,cn=0,bns=0;
    bool f=true;
    char c[20000],y,an[10000];
    cin>>n;
    cin>>a[0]>>c[0];
    long long j=1;
    for(int i=1;i<n;i++){
        cin>>x>>y;
        if(y==c[j-1]){
            a[j-1]+=x;
        }
        else{
            a[j]=x;
            c[j]=y;
            j++;
        }
    }
    for(int i=0;i<j;i++){
        cn+=a[i];
    }
    for(int i=1;i<j;i++){
        if(c[i]!=c[i-1]){
            f=false;
        }
    }
    if(f==true){
        cout<<"0"<<"\n";
        return 0;
    }
    if(cn<10000){
            long long m=0;
        for(int i=0;i<n;i++){
            for(int l=0;l<a[i];l++){
                an[m]=c[i];
                m++;
            }
        }
        for(int i=0;i<m/2;i++){
            if(an[i]!=an[m-i-1])
                bns++;
        }
        cout<<bns<<"\n";
        return 0;
    }

    //asdfghjkl;
    for(int i=0;i<j;i++){
        if(a[i]%2!=0)
            cnt++;
    }
    long long max;

    if(a[0]>a[j-1])
        max=a[0];
    else
        max=a[j-1];
    long long ans=cn/2;
    if(max<cn/2)
        ans-=cn/2-max;
    else
        ans-=max-cn/2;
    if(cnt%2!=0)
        ans--;
    cout<<ans<<"\n";
    return 0;
}
