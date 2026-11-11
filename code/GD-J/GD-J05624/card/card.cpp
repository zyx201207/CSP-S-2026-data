#include <bits/stdc++.h>
using namespace std;
int last[300005];
bool num[300005];
int card[500005];
int ans[300005];
int main(int argc, char** argv) {
	//auto st=clock();
	freopen("card4.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>card[i];
	}
	for(int t=1;t<=n;t++)
	{	
		memset(last,0,sizeof(last));
		memset(num,0,sizeof(num));
		for(int i=t;i<=n;i++)
		{
			
			if(last[card[i]]==0)
			{
				last[card[i]]=i;
				num[card[i]]=1;
			}
			else
			{
				for(int j=last[card[i]];j<i;j++)
				{
					num[card[j]]=0;
				}
				last[card[i]]=i;
				num[card[i]]=1;
			}	
		}
		for(int i=1;i<=m;i++)
			if(num[i])ans[i]++;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	//auto ed=clock;
	//cout<<endl<<ed-st;
	return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;

int last[300005];
bool num[300005];
int card[500005];
int ans[300005];
int main(int argc, char** argv) {
	auto st=clock();
	//freopen("card4.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>card[i];
	}
	for(int t=1;t<=n;t++)
	{	
		memset(last,0,sizeof(last));
		memset(num,0,sizeof(num));
		for(int i=t;i<=n;i++)
		{
			
			if(last[card[i]]==0)
			{
				last[card[i]]=i;
				num[card[i]]=1;
			}
			else
			{
				for(int j=last[card[i]];j<i;j++)
				{
					num[card[j]]=0;
				}
				last[card[i]]=i;
				num[card[i]]=1;
			}	
		}
		for(int i=1;i<=m;i++)
			if(num[i])ans[i]++;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	auto ed=clock;
	cout<<endl<<ed-st;
	return 0;
}
*/
