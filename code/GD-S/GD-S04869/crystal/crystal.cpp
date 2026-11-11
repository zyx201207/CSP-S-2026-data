#include<bits/stdc++.h>
using namespace std;
int n;long long m;
vector<long long> a;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		long long p;
		cin>>p;
		a.push_back(p);
	}
	sort(a.begin(),a.end());
	long long ans=0;long long cost=0;
	int i=0;
	while(cost<=m){
		cost+=i*(a[i+1]-a[i]);
		ans++;i++;
	}
	cout<<ans;
} 
