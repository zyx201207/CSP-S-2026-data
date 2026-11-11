#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll C,T,n,m,a[2000001],c[2000001],b,s;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>m;
		s=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<n;i++)
			for(int j=2;j<=n;j++)if(a[j]-a[i]<=m)c[i]=j;else break;
		for(int i=1;i<=n-2;i++)
			for(int j=i+2;j<=n;j++)
				if(j>c[i]){b=0;for(int k=i+1;k<j;k++)if(k<=c[i]&&j<=c[k])b++;if(b==2)s++;}
		cout<<s<<'\n';
	}
	return 0;
}
