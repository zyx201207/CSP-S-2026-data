#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t,n,d,a[1000];
int md(int x,int y){
    if(x==y) return 0;
    if(a[x+1]-a[x]>d) return 0;
	for(int i=x+1;i<=y;i++)
		if(a[i]-a[x]>d)
			return md(i-1,y)+1;
	return 1;
}
int check(int x,int y,int md,int nd){
	if(nd>md) return 0;
	if(x==y) return 1;
	int sum=0;
	for(int i=x+1;i<=y;i++){
		if(a[x]+d<a[i]) break;
		sum+=check(i,y,md,nd+1);
	}
	return sum;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				ans+=check(i,j,md(i,j),0)==2;
		cout<<ans<<'\n';
	}
	return 0;
}
