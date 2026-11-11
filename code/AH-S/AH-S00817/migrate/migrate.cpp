#include <bits/stdc++.h>
using namespace std;
int c,T;
int n;
long long d,a[2000010];
int t[2000010];
int minn=0x3f3f3f3f;
void dfs(int u,int cnt,int v){
	if(u==v){
		minn=min(minn,cnt);
		t[cnt]++;
		return;
	}
	if(cnt>minn) return;
	for(int i=u+1;i<=v;i++){
		if(a[i]-a[u]>d)
			break;
		dfs(i,cnt+1,v);
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+1+n);
		int cha=a[2]-a[1],flag=1;
		for(int i=3;i<=n;i++)
			if(a[i]-a[i-1]!=cha)
				flag=0;
		if(flag){
			if(d>=2*cha&&d<3*cha)
				cout<<n-3<<'\n';
			else
				cout<<0<<'\n';
		}else{
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=1;k<=j-i+1;k++)
						t[k]=0;
					minn=0x3f3f3f3f;
					dfs(i,0,j);
					if(minn!=0x3f3f3f3f&&t[minn]==2)
						ans++;
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
