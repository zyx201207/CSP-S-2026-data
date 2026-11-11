#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int sum=0;
bool vis[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int maxn=a[1];
    if(m==1){
        for(int i=1;i<=n;i++){
            maxn=max(maxn,a[i]);
        }
    }else if(m==2){
        maxn=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                maxn=max(maxn,a[i]&a[j]);
            }
        }
    }else if(m==n){
        for(int i=1;i<=n;i++){
            maxn=maxn&a[i];
        }
    }else if(m==n-1){
        int ans=1;
        for(int i=1;i<=n;i++){
            ans=ans&a[i];
        }
        maxn=0;
        for(int i=1;i<=a[i];i++){
            int b=0,aa=a[i];
            while(a){
                b=b*10;
                if(aa%10==0){
                    b+=1;
                }
                aa/=10;
            }
            maxn=max(maxn,ans&b);
        }
    }
    cout<<maxn;
    return 0;
}

