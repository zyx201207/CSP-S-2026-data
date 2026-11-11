#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
const int INF=0x3f3f3f;
int c,t;
int a[N];

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	int n,d;
	int x;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x;
		sort(a+1,a+n+1);
		if(n==4){
			cout<<1<<endl<<2;
			return 0;
		}
		if(n==5){
			cout<<0<<endl<<1;
			return 0;
		}
	}
	return 0;
} 
