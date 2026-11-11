#include<bits/stdc++.h>
using namespace std;
int a[500100]={0},ans[300100]={0},pos[300100]={0};
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	
	for(int i=1;i<=n;i++)
	{	
		memset(pos,0,sizeof(pos));
		vector<int> vec;
		for(int j=i;j<=n;j++)
		{
			if(pos[a[j]]==0) 
			{
				vec.push_back(a[j]);
				pos[a[j]]=1;
			}
			else
			{
				for(int k=vec.size()-1;vec[k]!=a[j];k--)
				{
					pos[vec.back()]=0;
					vec.pop_back();
				}
			}
		}
		for(int i=0;i<vec.size();i++) ans[vec[i]]++;
	} 
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
}
