#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
int maxans=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        int sum=0,ans=0;
        for(int j=1;j<i;j++){
            sum+=a[j];
            if((sum+m)/(i-1)==a[i]){
              ans=i;
            }
            if(ans>=maxans){
              maxans=ans;
            }
        }
    }
    cout<<max(maxans,1)<<'\n';
    return 0;
}