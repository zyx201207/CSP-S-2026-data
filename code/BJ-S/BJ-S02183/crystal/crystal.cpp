#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,a[500005],maxn=-1;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    for(int l=0;l<n-1;l++){
        for(int r=l;r<n;r++){
            int x=m;
            for(int i=l;i<=r;i++){
                if(x-a[r]+a[i]<0){
                    break;
                }else{
                    x-=a[r]-a[i];
                }
                if(i=r) maxn=max(maxn,i-l+1);
            }
        }
    }
    cout<<maxn;
    return 0;
}