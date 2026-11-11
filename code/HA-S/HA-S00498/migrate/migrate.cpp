#include<bits/stdc++.h>
using namespace std;
int c,t,n,s;
long long d,x[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int ti=1;ti<=t;ti++){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(d/(x[2]-x[1])<2)cout<<'0'<<'\n';
		else cout<<'1'<<'\n';
		break;
	}
	return 0;
}
