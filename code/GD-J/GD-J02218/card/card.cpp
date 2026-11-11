#include<bits/stdc++.h>
using namespace std;
const int N=3e5+7;
const int P=2e5+7;
int vec[P];
int ans[N]={0};
int cur[N]={0};
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n, &m);
	vector<int> cur;
	int s=0;
	for (int i = 0; i < n; i++) cin>>vec[i];
	for (int i = 0; i < n; i++)
	{
		if (i+1 == n)
		{
			for (int j = 0; j < s; j++)
			{
				ans[cur[j]] ++;
			}
		}
		cout<<cur[s]<<" "<<vec[i]<<endl;
		cur[s]=vec[i];
		printf("%d\n",s);
		if (s>=0){
			for (int j= 0; j < s-1; j++)
			{
				if(vec[i] == cur[j]) 
				{
					for (int k=j; j<s-1; j++) cur[k]=0; s=j;
				}
			}
			s++;
		}
	}
	for (int i=0;i<m;i++)
	{
		if (ans[i] != 0) 
		{
			printf("%d ",ans[i]);
		}
	}
}
