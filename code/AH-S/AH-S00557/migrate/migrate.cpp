#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> pii;
typedef unsigned long long ull;
int n,d;
vector<int> v;
void A(){
	int dif=v[1]-v[0];
	int mn=d/dif;
	cout<<(5-n)*2<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		v.clear();
		v.resize(n);
		for(int i=0;i<n;i++) cin>>v[i];
		bool fA=1;
		for(int i=2;i<n;i++){
			if(v[i]-v[i-1]!=v[1]-v[0]) fA=0;
		}
		if(fA) A();
	}
	
}
