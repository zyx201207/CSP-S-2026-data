#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,d,a[2000005],s[305][305],ans;
int dd(int st,int x,int y,int c){
	if(c>s[st][y]||x>y)return 0;
	if(x==y)return 1;
	int as=0;
	for(int i=1;i+x<=y&&a[i+x]-a[x]<=d;i++)as+=dd(st,x+i,y,c+1);
	return as;
}
signed main(){
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	cin>>t>>t;
	while(t--){
		cin>>n>>d,ans=0;memset(s,0,sizeof s);
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)for(int k=i;k<j;){
			int c=0;
			while(c+a[k+1]-a[k]<=d&&k<j)k++,c+=a[k]-a[k-1];
			s[i][j]++;
			if(s[i][j]>n)break;
		}
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(dd(i,i,j,0)==2)ans++;
		cout<<ans<<"\n";
	}
	return 0;
}
