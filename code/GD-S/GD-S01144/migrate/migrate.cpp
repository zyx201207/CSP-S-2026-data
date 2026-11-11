#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);/*
	int c,t;
	cin>>c>>t;
	while(t--) cout<<c*2+1+t/2<<"\n";*/
	map<int,int> m;
	m[1]=2;
	auto it=m.find(1);
	cout<<(it!=m.end());
	return 0;
} 
