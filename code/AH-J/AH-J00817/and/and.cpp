#include<bits/stdc++.h>
long long n,m,ans;
long long a[200005];
using namespace std;
int main(){
    freopen("and","r",stdin);
    freopen("and","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        long long c;
        cin>>c;
        a[i]=c;
    }
    if(m==1){
        long long maxn=0;
        for(int i=1;i<=n;i++){
            maxn=max(maxn,a[i]);
        }
        cout<<maxn;
        return 0;
    }else if(m==n){
        int ans=a[1];
        for(int i=2;i<=n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }else if(m==2){
        long long maxn=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int c=a[i];
                c=c&a[j];
                if(c>maxn)
                    maxn=c;
            }
        }
        cout<<maxn;
        return 0;
    }else if(m==n-1){
       sort(a+1,a+1+n);
       long long ans=a[n];
       for(int i=n-1;i>1;i--){
            ans=ans&a[i];
       }
       cout<<ans;
       return 0;
    }else if(n<=20){
        sort(a+1,a+1+n);
       long long ans=a[n];
       for(int i=n-1;i>n-m;i--){
            ans=ans&a[i];
       }
       cout<<ans;
       return 0;
    }else{
       sort(a+1,a+1+n);
       long long ans=a[n];
       for(int i=n-1;i>n-m;i--){
            ans=ans&a[i];
       }
       cout<<ans;
       return 0;
    }
    return 0;
}















