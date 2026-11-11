#include<bits/stdc++.h>
using namespace std;

int a[500005];
int b[300005];
int c[300005];
int auswer[500005];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(c,0,sizeof(c));
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
    	a[i]--;
    	c[a[i]]++;
	}
	memset(auswer,0,sizeof(auswer));

	for(int i=0;i<n;i++)
	{
		auswer[i]=i+1;
		b[a[i]]=i;
		for(int j=i-1;j>=0;j--)
		{
			if(c[a[j]]&&a[j]!=a[i]&&b[a[j]]==j)
			{
				auswer[i]-=auswer[j];
			}
		}
		c[a[i]]--;
	}

	for(int i=0;i<m;i++)
	{
		cout<<auswer[b[i]]<<" ";
	}

    return 0;
}
