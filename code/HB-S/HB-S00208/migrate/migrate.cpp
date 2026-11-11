#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d,cnt,cut;
long long a[5005];
long long book[5005];
long long labs(long long a){
	return (a>=0? a:-a);
}
void dfs(long long x,long long y,long long s){
	if(s>book[x]) return;
	book[x]=s;
	if(x==y){
		if(s==cnt) cut++;
		else{
			cnt=s;
			cut=0;
		}
	}
	for(int i=0;i<n;i++) if(labs(a[x]-a[i])<=d) dfs(i,y,s+1);
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.ont","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int f=0;
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<n-1;i++) for(int j=i+1;j<n;j++){
			for(int z=0;z<n;z++) book[z]=INT_MAX;
			cnt=0,cut=0;
			dfs(i,j,0);
			if(cut==1) f++;
		}
		cout<<f<<'\n';
	}
	return 0;
}
