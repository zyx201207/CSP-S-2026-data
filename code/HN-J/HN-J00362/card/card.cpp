#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	int num[100005];
	int a[200005],k[200005];
	for(int i = 1;i<=10002;i++) num[i]=0;
	cin>>n>>m;
	for(int i = 1;i<=n;i++) cin>>a[i];
	for(int i = 1;i<=n;i++)
	{
		//for(int c = 1;c<=200002;c++) k[c]=0;
		memset(k,0,sizeof(k));
		int t = 1;
		for(int j = i;j<=n;j++)
		{
			for(int l = 1;l<j;l++)
			{
				if(k[l]==a[j])
				{
					for(int g = l;g<j;g++){
						k[g]=0;
					}
					t = l;
				}
			}
			k[t] = a[j];
			t++;
		}
		for(int w = 1;w<t;w++) num[k[w]]++;
	}
	for(int i = 1;i<=m;i++) cout<<num[i]<<" ";
	return 0;
} 
//10 3
//3 1 2 1 3 2 3 1 2 1
