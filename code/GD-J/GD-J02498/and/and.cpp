#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,maxx,a[2005],b[2005];
bool s[2005][40005];
int main(){
	freopen("and.in","r",stdin); 
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=1;j<=40005;j++)
		{
			s[i][j]=a[i]%2;
			a[i]/=2;
			b[i]++;
			if(a[i]==0)break;
		}
	}
	cout<<maxx;
	return 0;
}
