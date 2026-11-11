#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int m,n,a[500010],b[500010],te[500010];
    bool flag=0,aflag=0;
    int mmax,mmin,flagg;
    int minn,maxx,fflag;
    int ans=1;
    int k;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    mmin=a[1];
    for(int i=2;i<=n;i++){
        if(a[i]<mmin){
            mmin=a[i];
        }
    }
    mmax=mmin;
    for(int j=1;j<=n;j++){
        for(int i=1;i<=n;i++){
            if(a[i]>mmax){
                mmax=a[i];
                flagg=i;
            }
        }
        b[j]=mmax;
        mmax=mmin;
        a[flagg]=mmin-1;
    }
    for(int i=1;i<=n-1;i++){
        if(b[i]-b[i+1]<=m){
            flag=1;
        }
    }
    k=b[1]-b[2];
    if(k!=0){
        for(int i=1;m>0;i++){
            m-=k*i;
            if(m>=0){
                ans++;
            }
        }
    }else{
        ans=n;
    }
    if(flag==0){
        cout<<++flag<<endl;
    }else{
        cout<<ans<<endl;
    }
    return 0;
}
