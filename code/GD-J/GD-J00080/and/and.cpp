#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=32;
int n,m,ans,idx;
int a[N];
string s[N];
int cnt[N*M];
int ind[N*M][2];
int ts[M];
string to2(int x){
	string tmp;
	while(x){
		tmp=tmp+(char)((x&1)+'0');
		x=x/2;
	}
	return tmp;
}
void build(string s,int u,int dp){
	if(dp==s.length())
		return;
	if(ind[u][s[dp]-'0']==0)
		ind[u][s[dp]-'0']=++idx;
	int v=ind[u][s[dp]-'0'];
	cnt[v]++;
	build(s,v,dp+1);
	if(s[dp]=='1')
	{
		if(ind[u][0]==0)
			ind[u][0]=++idx;
		int v=ind[u][0];
		cnt[v]++;
		build(s,v,dp+1);
	}
}
bool query(string s,int u,int dp){
	if(dp==s.length()){	
		if(cnt[u]>=m)
			return 1;
		return 0; 
	}
	int v=ind[u][s[dp]-'0'];
	if(cnt[v]<m)
		return 0;
	return query(s,v,dp+1);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		s[i]=to2(a[i]);
	}
	ts[0]=1;
	
	for(int i=1;i<M;i++)
		ts[i]=ts[i-1]<<1;
	for(int i=1;i<=n;i++){
		build(s[i],0,0);
}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=ans)
			continue;
		if(query(s[i],0,0))
			ans=a[i];
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
