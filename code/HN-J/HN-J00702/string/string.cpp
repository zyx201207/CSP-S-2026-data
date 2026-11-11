#include<bits/stdc++.h>
using namespace std;
int n;
long long ans; 
struct node
{
	int a;
	char c;
}p[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	
	for(int i=1;i<=n;i++) cin>>p[i].a>>p[i].c;
	if(n==1) ans=p[1].a;
	else
	{
		for(int i=1,j=n;i<j;)
		{
			int k=abs(p[i].a-p[j].a);
			if(k==0)
			{
				if(p[i].c!=p[j].c) ans+=p[i].a;
				i++,j--;
			}
			else
			{
				int l=min(p[i].a,p[j].a);
				if(p[i].c!=p[j].c) ans+=l;
				if(l==p[i].a) 
				{
					i++;
					p[j].a=k;
				}
				else
				{
					j--;
					p[i].a=k;
				}
			}
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
