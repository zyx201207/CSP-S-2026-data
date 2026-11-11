#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
bool pd[N];
int a[N];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m,sum=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=31;i>=0;i--){
		int ans=0;
       for(int j=1;j<=n;j++)
       if(!pd[j]&&(a[j]&(1<<i))) ans++;
       if(ans>=m) {
		   sum+=(1<<i);
		   for(int j=1;j<=n;j++)
		   if(!(a[j]&(1<<i))) pd[j]=true;
		   }
}
cout<<sum;
   return 0;
}
//guan zhu luogu cp_zry
//an wei tan xin
