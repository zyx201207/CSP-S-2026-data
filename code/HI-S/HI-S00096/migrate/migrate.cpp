#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		set<int> s;
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			s.insert(abs(x));
		}
		cout<<max(signed(s.size())-d-1,0)<<'\n';
	}
	return 0;
}
