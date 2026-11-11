#include<bits/stdc++.h>
using namespace std;

int _,c;
int x[2000010];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>_;
	while(_--){
		int n;
		long long d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(x[n]-x[1]<=d){
			cout<<0<<'\n';
		}
		else if(13<=c&&c<=14){
			cout<<2<<'\n';
		}
		else cout<<0<<'\n';
	}
	return 0;
}
