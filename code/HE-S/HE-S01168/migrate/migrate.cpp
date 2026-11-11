#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t,tsg;
	cin>>c>>t;
	int n[t],d[t],s[t]={0};
	for(int i=0;i<t;i++)
	{
		cin>>n[i]>>d[i];
		int x[n[i]];
		for(int j=0;j<n[i];j++)
		{
			cin>>x[j];//¾àÀë 
		}
		for(int p=n[i]-1;p>=0;p--)
		{
			for(int q=n[i]-1;q>=p;q--)
			{
				tsg=q-p;
				
				
				if(((tsg%d[i]==d[i]-1)&&((tsg/d[i]==1))&&(tsg!=1)))
				{
					if(x[q-1]!=x[p])
					{
						s[i]++;
					}
				}
			}
		}
		//cout<<s[i];
	}
	for(int s1=0;s1<t;s1++)
	{
		cout<<s[s1]<<endl;
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
