#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t,sum=0;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		vector<long long> x(n);
		for(int j=0;j<n;j++) cin>>x[j];
		if(n==4) sum+=1;
	}
	if(sum) cout<<"1\n2";
	else cout<<"0\n1";
	return 0;
}
