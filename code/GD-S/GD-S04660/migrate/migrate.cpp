#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000005],m,sum,ans,v[2000005],cnt,da[2000005];
void dfs(int x,int y,int k){
	if(x==y){
		da[++cnt]=k;
		sum=min(sum,k);
		return;
	}
	for(int i=1;i<=n;i++){
		if(abs(a[i]-a[x])<=d&&i!=x&&v[i]==0){
			v[i]=1;
			dfs(i,y,k+1);
			v[i]=0;
		}
	}
}
void solve(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		v[i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			m=0;
			sum=1e9;
			cnt=0;
			v[i]=1;
			dfs(i,j,0);
			v[i]=0;
			for(int g=1;g<=cnt;g++){
				if(da[g]==sum)m++;
				da[g]=0;
			}
			if(m==2)ans++;
		}
	}
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)solve();
	return 0;
}
