#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define p pair<ll,char>
#define FILE(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout);
int main(){
	FILE("string")
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll n,l=0;
	cin>>n;
	vector<p>v,v1;
	for(ll i=0;i<n;i++){
		ll c;
		char a;
		cin>>c>>a;l+=c;
		if(v.size()&&v.back().second==a)v.back().first+=c;
		else v.push_back({c,a}); 
	}ll sum=0,sum1=0,i=0;
	for(;sum<=l/2;i++)sum+=v[i].first;
	i--;
	for(ll j=v.size()-1;j>i;j--){
		if(v1.size()&&v1.back().second==v[j].second)v1.back().first+=v[j].first;
		else v1.push_back(v[j]);
		sum1+=v[j].first;
		v.pop_back();
	}p pr=v[i];
	v.pop_back();
	sum-=v[i].first;
	if(l/2-sum)v.push_back({l/2-sum,pr.second});
	if(l/2-sum1)v1.push_back({l/2-sum1,pr.second});
	sum=sum1=0;
	n=v.size();
	i=0;ll m=v1.size(),j=-1,ans=0;
	for(;i<n&&j<m-1;i++){
		if(sum<sum1&&v[i].second!=v1[j].second)ans+=min(v[i].first,sum1-sum);
		sum+=v[i].first;
		while(sum>sum1){
			if(v[i].second!=v1[++j].second)ans+=min(v1[j].first,sum-sum1);
			sum1+=v1[j].first;
		}
	}
	cout<<ans;
}
