#include <bits/stdc++.h>
using namespace std;
long long c,t,n,m,a[999999],ge,ss,g,he,st2;
void dfs(long long st,long long ed,long long ci){
	if(st==ed){
		if(ci==ss){
			ge++;
		}
		return ;
	}
	he=0,st2=st;
	while(he<=m && st<=ed){
		he=he+a[st+1]-a[st];
		st++;
	}
	st--;
	for(long long i=st2+1;i<=st;i++){
		dfs(i,ed,ci+1);
	}	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(long long i=1;i<=t;i++){
		cin>>n>>m;
		for(long long j=1;j<=n;j++){
			cin>>a[j];
		}
		g=0;
		for(long long j=1;j<=n;j++){
			for(long long k=j+1;k<=n;k++){
				ge=0;
				ss=(a[k]-a[j]-1)/m+1;
				dfs(j,k,0);
				if(ge==2){
					g++;
				}
			}
		}
		cout<<g<<endl;
	}
	
	return 0;
}
