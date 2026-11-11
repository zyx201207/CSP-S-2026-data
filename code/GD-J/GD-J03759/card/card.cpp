#include<iostream>
using namespace std;
const int MX=5e5+5;
int n,m,a[MX],ans[MX];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int tmp[MX]={0},q=0;
		for(int j=i;j<=n;j++)
		{
			bool flag=false;
			int pos=0;
			for(int k=1;k<=q;k++)
			{
				if(a[j]==tmp[k])
				{
					flag=true;
					pos=k;
					break;
				}
			}
			if(flag)
			{
				for(int k=pos;k<=q;k++)
				{
					tmp[k]=0;
				}
				q=pos;
				tmp[q]=a[j];
			}
			else
			{
				tmp[++q]=a[j];
			}
		}
		for(int j=1;j<=q;j++)
		{
			ans[tmp[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
} 
