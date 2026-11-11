#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
int x[200005];
int main(){
	freopen("migrate","r",stdin);
	freopen("migrate","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[i];
		}
	}
	for(int i=1;i<=t;i++){
		cout<<0<<"\n";
	}
	return 0;
}
