#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> v;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	v.resize(n,0);
	for(int i=1;i<=n;i++){
		cin>>v[i-1];
	}
	cout<<rand();
	return 0;
}
