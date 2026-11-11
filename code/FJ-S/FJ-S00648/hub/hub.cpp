#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,p,q,ans,v[1005],df[1005];
vector<vector<long long> > a;
void dfs2(long long x,long long f){
	if(df[f]+1>df[x] && f!=0) return;
	df[x]=df[f]+1;
	int l=a[x].size();
	for(int i=0;i<l;i++){
		dfs2(a[x][i],x);
	}
}
long long js(){
	long long jk=0;
	for(int i=1;i<=n;i++){
		df[i]=1e17;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==1){
			dfs2(i,0);
		}
	}
	for(int i=1;i<=n;i++){
		jk=max(df[i],jk);
	}
	return jk;
}
void dfs(long long x,long long h){
	if(x==0){
		ans=min(ans,js());
		return;
	}
	for(int i=h+1;i<=n;i++){
		v[i]=1;
		dfs(x-1,i);
		v[i]=0;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=1e17;
		a.resize(n+1);
		for(int i=1;i<n;i++){
			cin>>p>>q;
			a[p].push_back(q);
			a[q].push_back(p);
		}
		for(int i=1;i<=n;i++){
			df[i]=1e17;
		}
		df[0]=-1;
		v[1]=1;
		v[4]=1;
		dfs(d,0);
		cout<<ans<<endl;
	}
	return 0;
}

