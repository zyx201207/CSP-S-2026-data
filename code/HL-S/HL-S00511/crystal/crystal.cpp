#include<bits/stdc++.h>
using namespace std;
int n,m,s=1;
vector<long long> a;
long long p[555555];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	p[0]=0;
	for(long long i=1;i<=n;i++){
		long long x;cin>>x;
		a.push_back(x);
		p[i]=p[i-1]+x;
	}
	sort(a.begin(),a.end());
	for(long long i=2;i<=n;i++){
		if(abs(a[i-1]*i-p[i])<=m){s++;}
		else{break;}
	}
	cout<<s;
	return 0;
}