#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool f(int a){
    int y;
    while(a){
        y=a%2;
        if(y==0&&a==2) return 1;
        if(y==1) return 0;
        a/=2;
    }
    return 1;
}
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n-m==1){
        int ans=a[1],t=-1;
        for(int i=2;i<=n;i++){
            ans=ans&a[i];
        }
        int k;
        for(int i=1;i<=n;i++){
            k=ans&a[i];
            t=max(t,k);
        }
        cout<<t;
        return 0;
    }
    sort(a+1,a+n+1,cmp);
    int t=-1,ans=a[1],ii,jj;
    if(m==1){
        cout<<ans;
        return 0;
    }
    if(m==n){
       for(int i=2;i<=n;i++){
            ans=ans&a[i];
       }
       cout<<ans;
       return 0;
    }
    if(m==2){
        bool z=0;
        if(a[n]==0) z=1;
        if(f(ans)==1 && z==1){
            cout<<ans-1;
            return 0;
        }
        else{
            for(int i=1;i<=n-1;i++){
                for(int j=i+1;j<=n;j++){
                    //cout<<t<<' '<<a[i]<<' '<<a[j]<<endl;
                    t=max(t,a[i]&a[j]);
                }
            }
            cout<<t;
            return 0;
        }
    }
    if(n<=20 && m<=n){
        for(int i=1;i<=n-m;i++){
            ans=a[i];
            for(int j=i+1;j<=m;j++){
                ans=ans&a[j];
                //cout<<t<<' '<<ans<<endl;
            }
            t=max(t,ans);
        }
        cout<<t;
        return 0;
    }
    return 0;
}



