#include <bits/stdc++.h>
using namespace std;
int c,t,cnt=INT_MAX,ans=0;
int n;
long long d;
long long a[2000005];
/*void dfs2(int nl,int st,int ed,int mn){
	if(nl==ed){
		if(mn==cnt)ans++;
		return;
	}
	for(int i=nl+1;i<=ed;i++){
		if(a[nl]+d<=a[i]){
			dfs2(i,st,ed,mn+1);
		}
	}
}
void dfs(int nl,int st,int ed,int mn){
	if(mn>=cnt)return;
	if(nl==ed)cnt=min(cnt,mn);
	for(int i=ed;i>=nl+1;i--){
		if(a[nl]+d>=a[i]){
			dfs(i,st,ed,mn+1);
		}
	}
}*/
bool s(int st,int ed){
/*	dfs(st,st,ed,0);
//	int mn=cnt;//(a[ed]-a[st])/d;
	dfs2(st,st,ed,0);
	//cout<<a[ed]-a[st]<<" "<<endl;
*/	
	
	if((ed-st)*d<(a[ed]-a[st])){
		return false;
	}
	if(a[ed]-a[st]==(2*d-1)){
		return true;
	}
	return false;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		ans=0;
		for(int i=1;i<=n-3;i++){
			for(int j=i+3;j<=n;j++){
				cnt=0;
				
				if(s(i,j))ans++;
			}
		}
		cout<<ans<<endl;
	}
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
/*dfs(i,i,j,0);
				dfs2(i,i,j,0);*/
 //	int mn=cnt;//(a[ed]-a[st])/d;
