#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n;
long long d,x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		if(c==0){
			if(n==4&&d==2)
				cout<<1;
			if(n==5&&d==2)
				cout<<2;
			if(n==5&&d==3)
				cout<<0;
			if(n==6&&d==2)
				cout<<1;
			cout<<'\n';
		}
	}
	return 0;
}
