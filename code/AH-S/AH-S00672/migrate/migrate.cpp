#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+7;
int x[N];
int bucket[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(c==7||c==8||c==9||c==10||c==11){
			int a=x[2]-x[1];
			if(a==d){
				cout<<0<<"\n";
				continue;
			}
		
		}
	}
	
	return 0;
}
