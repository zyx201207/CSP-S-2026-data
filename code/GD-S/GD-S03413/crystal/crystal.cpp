#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll m;
vector<ll> g;
ll in(){
	ll f=1,ans=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c==45)
			f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		ans=ans*10+c-48;
		c=getchar();
	}
	return f*ans;
}
bool check(int x){
	ll s=0;
	for(int i=0;i<x;++i)
		s+=g[i];
	if(m>=x*g[x-1]-s)
		return 1;
	for(int i=x;i<n;++i){
		s+=g[i];s-=g[i-x];
		if(m>=x*g[i]-s)
			return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n;m=in();
	for(int i=0;i<n;++i)
		g.push_back(in());
	sort(g.begin(),g.end());
	int l=1,r=n;
	int mid,ans=1;
	while(l<=r){
		mid=l+r>>1;
		if(check(mid)){
			ans=max(ans,mid);
			l=mid+1;
		}
		else
			r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}
