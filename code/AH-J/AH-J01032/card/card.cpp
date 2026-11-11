#include<bits/stdc++.h>
using namespace std;
//const int N=5e5+10;
int n,m;
//int opts[N],optn,ans[N];
//bool optenble[N];
int main()
{
	freopen("card.in" ,"r",stdin );
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++) cout<<"0 ";
	/*for(int i=1;i<=n;i++)
	{
		cin>>cards[i];
	}
	for(int i=1;i<=m;i++)
	{
		optn=0;
		for(int j=i;j<=n;j++)
		{
			bool find=false;
			for(int k=1;k<=optn;i++)
			{
				if(optenble[k]||opts[i]==cards[j])
				{
					find=true;
					optn=k;
					break;
				}
			}
			if(!find) optn++;
			opts[optn]=cards[j];
		}
		for(int j=1;i<=optn;j++)
		ans[opts[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	cout<<ans;*/
}
