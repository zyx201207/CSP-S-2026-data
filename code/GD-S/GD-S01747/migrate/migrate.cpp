#include<bits/stdc++.h>
using namespace std;
int s,n,m,d,q,ans;
int w[50005];
long long f[50005];
long long nm[50005];
void work(int k,int t){
	for(int i=k-1;i>=1;i--)
	{
		if(w[k]-w[i]<=d)
		{
			if(nm[i]){
			//	cout<<i<<'|'<<t<<':';
				for(int j=1;j<=nm[i];j++)
				{
					//cout<<f[j]<<' ';
					if(f[j]==t)
					{
						//cout<<i<<' ';
						ans++;
						return;
					}
				}
				f[++nm[i]]=t+1;
				work(i,t+1);
			}
			else
			{
				f[++nm[i]]=t+1;
				work(i,t+1);
			}
		}
		else break;
	}
	
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>s>>q;
	while(q--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>w[i];
			for(int j=1;j<i;j++)
			{
				f[j]=0;
				nm[j]=0;
			}
			//cout<<i<<'#';
			work(i,1);
			//cout<<"\n";
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
