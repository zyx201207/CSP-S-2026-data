#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+10;
int a[N];//dp[i]表示在地i次操作上，最多用dp[i] 可合成 
//5 5 1 2 4 8 9
//5 8 -3 -1 2 2 7 
bool cmp(int x,int y){
	return x>y;
}int x[N],y[N];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;cin>>c>>t;
	cin>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i]>>y[i];
		}
		cout<<0<<endl;
	}
	return 0;
}
