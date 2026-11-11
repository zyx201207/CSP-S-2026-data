#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
ll s[500005],k[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<=n;i++)
	{
		int len=i-1;
		for(int j=i;j<=n;j++)
		{
			for(int l=len+1;l<j;l++){
				if(s[l]==s[j])
				{
					len=max(len,j-1);
				}			
			}
		}
		for(int j=len+1;j<=n;j++)
		{
			k[s[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<k[i]<<' ';
	}
	return 0;
}
