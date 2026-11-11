#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll w[500005],t[505][100005],ans,c,a,n,m,d,q,k,x,y;
bool v[505][100005];

/*
地铁线路数 n
地铁站数 m
每个地铁站最多被几条线路经过 d
以及出行计划数 q
*/
void f(ll ro,ll st,ll ti){
	if(v[ro][st])return ;
	v[ro][st]=1;
	if(st==y){
		ans=min(ans,ti+t[ro][st]);
		return ;
	}
	for(int i=1;i<=m;i++){
		if(t[ro][i]!=0 && i!=st)f(ro,i,ti);
	}
	for(int i=1;i<=n;i++){
		if(t[i][st]!=0 && i!=ro)f(i,st,ti+t[ro][st]+t[i][st]);
	}
	
	
	return ;
}

int main(){
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a;
			cin>>t[i][a];
			
		}
		
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		for(int j=1;j<=n;j++){
			memset(v[j],0,d);	
		}
		ans=4e18;
		for(int j=1;j<=n;j++){
			if(t[j][x]!=0)f(j,x,t[j][x]);	
		}
		
		cout << ans+w[x]+w[y];
	}
	
	fclose(stdin);fclose(stdout);
	return 0;
	
} 
