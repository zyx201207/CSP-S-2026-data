#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
string c[200005];
struct number{
	long long gs;
	string z;
}zm[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	long long tmp=0;
	for(int i=1;i<=n;i++)
	{
		tmp++;
		zm[tmp].gs+=a[i];
		zm[tmp].z=c[i];
		while(c[i]==c[i+1])
		{
			zm[tmp].gs+=a[i+1];
			i++;
		}
	}
	if(tmp==1)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=tmp/2;i++)
	{
		if(zm[tmp-i+1].z!=zm[i].z)
		{
			if(zm[i].gs==zm[tmp-i+1].gs)
			{
				ans+=zm[i].gs;
			}
			else if(zm[i].gs>zm[tmp-i+1].gs)
			{
				ans+=zm[tmp-i+1].gs;
				zm[i].gs-=zm[tmp-i+1].gs;
				tmp--,i--;
			}
			else{
				ans+=zm[i].gs;
				zm[tmp-i+1].gs-=zm[i].gs;
				tmp++;
			}
		}
		else if(zm[i].gs!=zm[tmp-i+1].gs)
		{
			if(zm[i].gs>zm[tmp-i+1].gs)
			{
				ans+=zm[tmp-i+1].gs;
				zm[i].gs-=zm[tmp-i+1].gs;
				tmp--,i--;
			}
			else{
				ans+=zm[i].gs;
				zm[tmp-i+1].gs-=zm[i].gs;
				tmp++;
			}
		}
	}
	cout<<ans;
	return 0;
}
