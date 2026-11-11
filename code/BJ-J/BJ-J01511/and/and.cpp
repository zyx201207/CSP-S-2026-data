#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],p,q;
int maxn=-1;
int visit[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            maxn=max(maxn,a[i]);
        }
        cout<<maxn;
    }else if(m==2){
        int p=0,q=0;
        for(int i=1;i<n-1;i++){
            for(int j=i+1;j<=n;j++){
                int k=a[i]&a[j];
                maxn=max(maxn,k);
            }
        }
        cout<<maxn;
    }else if(m==n){
        maxn=a[1];
        for(int i=2;i<=n;i++){
            maxn=maxn&a[i];
        }
        cout<<maxn;
    }else{
        sort(a+1,a+n+1);
        cout<<a[n-m+1];
    }
    return 0;
}
