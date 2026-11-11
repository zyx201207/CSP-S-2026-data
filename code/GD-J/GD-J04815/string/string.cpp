#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	
	vector<pair<int,char>>a(n+1);
	for(int i=1;i<=n;++i)cin>>a[i].first>>a[i].second;
	vector<pair<ll,char>>d;
	d.reserve(n);
	for(int i=1;i<=n;){
		char op=a[i].second;
		ll sum=0;
		while(a[i].second==op){
			sum+=a[i].first;
			++i;
		}
		d.emplace_back(sum,op);
	}
	
	n=d.size();
	int i=0,j=n-1;
	ll ans=0;
	while(i<j){
		if(d[i].first>d[j].first){
			d[i].first-=d[j].first;
			if(d[i].second!=d[j].second)ans+=d[j].first;
			--j;
		}else if(d[i].first==d[j].first){
			if(d[i].second!=d[j].second)ans+=d[i].first;
			++i,--j;
		}else{
			d[j].first-=d[i].first;
			if(d[i].second!=d[j].second)ans+=d[i].first;
			++i;
		}
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
