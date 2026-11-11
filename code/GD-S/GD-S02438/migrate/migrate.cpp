#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+1e2;
int c,t,x[N],l[N][N],s[N][N];
int n,d;
int main()
{
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		memset(l,0xffff,sizeof l);
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j&&abs(x[i]-x[j])<=d){
					l[i][j]=l[j][i]=1;
				}
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=i;j<=n;j++)
					if(i!=j&&i!=k&&j!=k){
						if(l[i][j]==l[i][k]+l[k][j])s[i][j]++;
						l[i][j]=min(l[i][j],l[i][k]+l[k][j]);
					}
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++)
				if(s[i][j]==1)cnt++;
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
