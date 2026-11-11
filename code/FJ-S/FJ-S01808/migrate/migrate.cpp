//+8pts
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,t;
int n,d,a[N];
void solveA(){
	int x=a[2]-a[1];
	int s=d/x;
	if(s==0||s==1)cout<<0<<'\n';
	else cout<<max(n+1-2*s,0ll)<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		solveA();
	}
	return 0;
}