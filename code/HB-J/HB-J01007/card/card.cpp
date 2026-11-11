#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int n,m,a[500005],b[300005],c[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    For(i,1,n)cin>>a[i];
    For(i,1,n){
        for(int w=i;w<=n;w++)c[i]=1;
        For(j,i+1,n){
            For(k,i,j-1){
                if(a[k]==a[j]&&c[k]==1){

                For(w,k,j-1)c[i]=0;
                }
            }
        }
        For(w,i,n)if(c[i]==1)b[a[i]]++;
    }
    For(i,1,m)cout<<b[i]<<" ";
    return 0;
}
