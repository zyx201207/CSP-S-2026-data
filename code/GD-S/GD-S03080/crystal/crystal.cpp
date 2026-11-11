#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
vector<long long>a,b;
map<long long,int>mp;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	a.resize(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]++;
	}
	int maxs=0;
	for(auto& p:mp){
		maxs=max(maxs,p.second);
	}
	for(auto& p:mp){
		if(p.second==maxs)b.push_back(p.first);
	}
	long long res=maxs;
	for(auto& v:b){
		long long sum=maxs;
		vector<int>c;
		for(int i=1;i<=n;i++){
			if(a[i]>=v)continue;
			c.push_back(v-a[i]);
		}
		sort(c.begin(),c.end());
		for(auto& u:c){
			if(m>=u){
				m-=u;
				sum++;
			}
		}
		res=max(sum,res);
	}
	printf("%lld",res);
	return 0;
}
