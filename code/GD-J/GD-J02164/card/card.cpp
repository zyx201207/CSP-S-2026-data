#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		b[a[i]]++;
		if(b[a[i]]>1){
			for(int j=0;j<i;j++)
			{
				if(a[i]==a[j])
				{
					i=j;
					break;
				}
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<a[i];
	}
	return 0;
 } 
