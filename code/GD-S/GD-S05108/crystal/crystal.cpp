#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,m,ans=0,cnt=1,mn=1e9,mx=-1e9;
struct jtm{
	long long a,c;
}d;
vector<jtm>name;
long long s[N];
bool cmp(jtm x,jtm y){
	return x.a<y.a;
}
bool na(jtm x,jtm y){
	if(x.c==y.c)return x.a<y.a;
	return x.c>y.c;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long t=1;t<=n;t++){
		cin>>d.a;
		name.push_back(d);
	}
	sort(name.begin(),name.end(),cmp);
	for(long long t=1;t<=n;t++){
		name[t].c=name[t].a-name[t-1].a;
		mn=min(name[t].c,mn);
		mx=max(name[t].c,mx);
		s[t]=abs(name[t].c)+s[t-1];
	}
	if(mx==mn){
		cout<<0;
		return 0;
	}
	if(mn>m){
		cout<<0;
		return 0;
	}
	else if(mn==m){
		cout<<2;
		return 0;
	}
	name[1].c=name[2].c;
	for(long long t=n-1;t>0;t--){
		for(long long i=1;i<n;i++){
			if(s[t]-s[i]<=m){
				ans=max(ans,t-i+1);
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
