#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll c,t,n,d,x[1000001],o,s,num,u,w;

void dfs(ll l,ll r,ll p){
	if(p>s || o>2) return; 
	if(l==r){
		if(s==p) o++;
		else if(s>p) {
			s=p;
			o=1;
		}
		return ;
	}
	for(int i=l+1;i<=r;++i){
		if(x[i]-x[l]<=d) dfs(i,r,p+1);
	}
}


int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		num=0;u=0;w=0;
		cin>>n>>d;
		for(int i=1;i<=n;++i) {
			cin>>x[i];
			if(i==2) u=x[i]-x[i-1];
			if(x[i]-x[i-1]!=u) w=1;
		}
		if(w==0){
			cout<<n-d/u*2+1<<endl;
			continue;
		}
		else{
			for(int i=1;i<=n;++i){
			for(int j=i+3;j<=n;++j){
				o=0;s=999999;
				dfs(i,j,0);
				if(o!=2) continue;
				num++;
			}
		}
		cout<<num<<endl;
	}
	}
	
	return 0;
 } 
