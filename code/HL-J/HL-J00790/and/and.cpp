#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e8+10;
int a[N];
int mn=0x3f3f3f3f;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	   int n,m;cin>>n>>m;
	   int mx=0;
	   for(int i=1;i<=n;i++){
	   	cin>>a[i];
	   }
	   	sort(a,a+n+1);
	   	for(int i=n;i>=n-m+1;i--){
	   		if(m==1){
	   			cout<<a[i];
	   			return 0;
			   }
		mn=min(a[i],mn);
		}
		
	   cout<<mn;
	   return 0;
}
