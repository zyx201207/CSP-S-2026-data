#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
long long a[maxn],l,r,ans=1,cnt=1,x,res[maxn],sum[maxn];//v:²îÖµÊý×é
map<long long,int> mp;
long long co(int l,int r) {
	int c=1;
	long long p=0;
	for(int i=l; i<r; i++) {
		p+=res[i]*c;
		c++;
	}
	return p;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		mp[a[i]]++;
	}
	for(auto v:mp) {
		for(int i=1; i<=v.second; i++)res[cnt++]=v.first;
	}
	for(int i=1; i<n; i++) {
		res[i]=res[i+1]-res[i];
		sum[i]=sum[i-1]+res[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			long long p=co(i,j);
			if(p<=m)ans=max(ans,1ll*j-i+1);
		}
	}
	cout<<ans;
	return 0;
}
