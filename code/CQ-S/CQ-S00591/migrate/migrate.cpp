#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,d,a[2000001],c,t,b[2000001],x;
int dfs(int u,int v,int f){
	int s=0;
	if(u==v&&f==x)return 1;
	for(int i=u+1;i<=b[u];i++)s+=dfs(i,v,f+1);
	return s;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		int s=0;
		cin>>n>>d;
		if(n>5000){cout<<"0\n";continue;}
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=2;i<=n;i++)
			if(a[i]-a[i-1]>d)n=i-1;
		for(int i=1;i<=n-1;i++){
			int j=i+1;
			while(a[j]-a[i]<=d&&j<=n)++j;
			b[i]=j-1;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				x=1;int k=b[i],m;
				while(k<j){x++;k=b[k];}
				if(x>1){
					m=dfs(i,j,0);
					if(m==2)s++;
				}
			}
		}
		cout<<s<<"\n";
	}
	return 0;
}
