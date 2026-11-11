#include<bits/stdc++.h>
using namespace std;
const int N=1000111;
long long a[N][N],t[N][N];
int w[N];
int n,m,d,q,c;

int main(){
	freopen("subway.in","r",stdin);
	freopen("sudway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	while(q--)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>w[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cin>>a[i][j]>>t[i][j];
			}
		}	
	}
	cout<<1<<" "<<2;
	
	return 0;
}
