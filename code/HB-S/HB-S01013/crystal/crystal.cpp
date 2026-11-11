#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
double sum;
int a[10];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
   sum=1.0*sum/n;
   for(int j=n;j>=1;j--){
        while(sum>a[j]&&sum-a[j]>=1&&m>=1){
            a[j]++;
            m--;
        }
        if(a[j]==a[j+1]) ans++;
   }
   cout<<ans;
   return 0;
}
