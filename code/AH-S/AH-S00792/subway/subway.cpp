#include <bits/stdc++.h>
using namespace std;
long long w[500005],k[505];
vector<long long> a[505],t[505];
vector<long long> b[500005];
long long s[500005];
long long c,n,m,d,q;
bool f1(){
	for(long long i=1;i<=n;i++){
		if(k[i]>2){
			return false;
		}
	}
	return true;
}
void d1(long long x,long long y,long long cnt){
	if(x==y){
		return;
	}
	for(auto u:b[x]){
		long long i=0;
		for(;i<=n;i++){
			if(a[u][i]==x){
				break;
			}
		}
		long long j=0;
		for(auto v:a[u]){
			if((!s[v] or cnt+t[u][i]+t[u][j]<s[v]) and v!=x){
				s[v]=cnt+t[u][i]+t[u][j];
				d1(v,y,s[v]);
			}
			j++;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){
		cin>>k[i];
		for(long long j=1;j<=k[i];j++){
			long long x,y;
			cin>>x>>y;
			a[i].push_back(x);
			t[i].push_back(y);
			b[x].push_back(i);
		}
	}
	while(q--){
		memset(s,0,sizeof(s));
		long long x,y;
		cin>>x>>y;
		d1(x,y,0);
		cout<<s[y]+w[x]+w[y]<<endl;
	}
	
	return 0;
}

