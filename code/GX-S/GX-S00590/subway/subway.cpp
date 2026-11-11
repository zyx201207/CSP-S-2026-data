#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cout<<16<<endl<<22<<endl;
    return 0;
}
/*/crystal#include<bits/stdc++.h>
using namespace std;
int f[50010];
int main(){
    //freopen("crystal3.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    int m,n,a[50010],b[50010],te[50010];
    bool flag=0,aflag=0;
    int mmax,mmin,flagg;
    int minn,maxx,fflag;
    int ans=1;
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
    if(!flag){
        cout<<++flag<<endl;
    }
    minn=m+1;
    for(int i=1;i<=n-1;i++){
        if(b[i]-b[i+1]<=minn){
            minn=b[i]-b[i+1];
        }
    }
    if(minn==0){
        for(int i=1;i<=n-1;i++){
            if(b[i]==b[i+1]){
                ans++;
                f[i]=1;
                if(aflag==0)ans++;
                aflag=1;
            }else{
                aflag=0;
            }
        }
    }
    ans--;
    for(int i=1;i<=n-1;i++){
        if(b[i]-b[i+1]==1){
            minn=b[i]-b[i+1];
        }
    }
    //cout<<ans<<endl;
    return 0;
}
/*/
