#include<bits/stdc++.h>
using namespace std;
long long m,n,sum,a,k,b;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>a>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>n>>k;
		for(int j=1;j<=n;j++)
		{
			cin>>b;
		}
		for(int j=1;j<=n;j++)
		{
			if((j+=k+1)<=n){
				sum++;
			}
		}
		cout<<sum;
	}	
	return 0;
}
