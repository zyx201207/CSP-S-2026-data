#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long n,m,maxx;
void dfs(long long x,long long sum,long long sx){
	if(sx==m){
		maxx=max(maxx,sum);
		return ;
	}
	for(int i=x+1;i<=n;i++){
		dfs(i,sum&a[i],sx+1);
	}
} 
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++) cin>>a[i];
for(int i=1;i<=n;i++)
{
	dfs(i,a[i],1);
}
cout<<maxx;
return 0;
}

