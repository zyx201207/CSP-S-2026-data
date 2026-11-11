#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,shu=0,qi,zhong,min=0;


int main()
{	

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);
	cout.tie(0); 
	cin>>c>>n>>m>>d>>q;
	int b[n][m];
int a[m],c[m][m];
	for(int i=0;i<m;i++)
	cin>>a[i];
	
	for(int i=1;i<=n;i++)
	{
		cin>>b[i][0];
		{
			for(int l=1;l<=b[i][0]*2;l++)
			{
			cin>>b[i][l];
			if(l%2!=0)
			c[i][b[i][l]]=1;	
			}
		}
	 } 
	 while(q)
	 {
	 	cin>>qi>>zhong;
	 	q--;
	 }
	return 0;
}
