#include<bits/stdc++.h>
using namespace std;
struct sss
{
	long long s;
	char t;
}q[100000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,zs=0;
	cin>>n;
	string a;
	for(int i=1;i<=n;i++)
	{
		cin>>q[i].s>>q[i].t;
		zs+=q[i].s;
	}
	long long l=1,r=n,ans=0,dl=1,dr=zs;
	while(dl<dr&&l<r)
	{
//		cout<<ans<<" "<<l<<" "<<r<<" "<<dl<<" "<<dr<<endl;
		if(q[l].t!=q[r].t)
		{
			ans+=min(q[l].s,q[r].s);
			if(q[l].s>q[r].s)
			{
				q[l].s-=q[r].s;
				dr-=q[r].s;
				r--;
			}
			else if(q[l].s<q[r].s)
			{
				q[r].s-=q[l].s;
				dl+=q[l].s;
				l++;
			}
			else if(q[l].s==q[r].s)
			{
				dl+=q[l].s;
				dr-=q[r].s;
					q[r].s=0;
				q[l].s=0;
				l++;
				r--;
			}
		}
		else
		{
			if(q[l].s>q[r].s)
			{
				q[l].s-=q[r].s;
				dr-=q[r].s;
				r--;
			}
			else if(q[l].s<q[r].s)
			{
				q[r].s-=q[l].s;
				dl+=q[l].s;
				l++;
			}
			else if(q[l].s==q[r].s)
			{
				dl+=q[l].s;
				dr-=q[r].s;
				q[r].s=0;
				q[l].s=0;
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}

