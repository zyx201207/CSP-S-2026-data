#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000000],table[1000000],ans[1000000],leth;
void ts(int i,int j,int k,int leth)
{
	cout<<"k:"<<k<<" "<<"j:"<<j<<" "<<"I:"<<i<<endl;
	cout<<"le:"<<leth<<" "<<"aj"<<a[j]<<endl;
	for(int w=1;w<=leth+1;w++)
	{
		cout<<table[w]<<" ";
	}
	cout<<endl;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		leth = 0;
		for(int j=i;j<=n;j++)
		{
			bool s = false;
			int neleth = leth;
			for(int k=1;k<=leth;k++)
			{
				if(s)
				{
					table[k] = -1;
					neleth--;
					//cout<<"@@";
				//	ts(i,j,k,leth);
				}
				if(table[k] == a[j])
				{
					table[k] = -1;
					s = true;
					neleth--;
				//	cout<<"**";
				//	ts(i,j,k,leth);
				}
			}
			leth = neleth;
			table[leth+1] = a[j];
			leth++;
		//	cout<<"##";
		//	ts(i,j,0,leth);
		}
//		cout<<"##";
//		ts(i,0,0);
		for(int j=1;j<=leth;j++)
		{
			ans[table[j]]++;
			table[j] = -1;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
