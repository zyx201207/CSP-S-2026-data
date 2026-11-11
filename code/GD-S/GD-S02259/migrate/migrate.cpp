#include<bits/stdc++.h>
using namespace std;
int c,t,n,minm,u,v,s,ans;
long long d,a[2000005];
void move(){
	int l=u,r;
	while(l<=v){
		r=l+1;
		while(r<=v&&a[r]-a[l]<=d) r++;
		l=r;
		minm++;
	}
}
void dfs(int m,int x){
	if(m>minm) return;
	if(x==v){
		s++;
		return;
	}
	for(int i=x+1;a[i]-a[x]<=d&&i<=v;i++){
		dfs(m+1,i);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(c==11||c==12){
			int b=a[2]-a[1];
			if(d<b*2||d>=a[n]-a[1]){
				cout<<0<<"\n";
			}
			else{;
				cout<<n-d/b*2+1<<"\n";
			}
			continue;
		}
		ans=0;
		for(int i=1;i<=n-3;i++){
			for(int j=i+3;j<=n;j++){
				s=0;
				minm=0;
				u=i;
				v=j;
				move();
				dfs(0,i);
				if(s==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
