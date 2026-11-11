#include <bits/stdc++.h>
using namespace std;
struct node{
	long long n;
	char c;
};
int n;
node a[200010];
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].n>>a[i].c;
	}
	int l=1,r=n;
	long long ln=a[l].n,rn=a[r].n;
	char lc=a[l].c,rc=a[r].c;
	while(l<r)
	{
		//cout<<"w"<<" "<<"ln="<<ln<<"  "<<"rn="<<rn<<endl;
		//cout<<"w"<<" "<<"l="<<l<<" "<<"r="<<r<<endl;
		if(lc!=rc)
		{
			if(ln==rn)
			{
				ans+=ln;
				l++,r--;
				ln=a[l].n,rn=a[r].n;
				lc=a[l].c,rc=a[r].c;
				//cout<<ans<<"*"<<endl;
			}
			else
			{
				if(ln>rn)
				{
					ans+=ln-rn;
					ln-=rn;
					r--;
					rn=a[r].n;
					rc=a[r].c;
				//	cout<<ln<<" "<<rn<<endl;
				//	cout<<ans<<"**"<<endl;
				}
				else
				{
					ans+=rn-ln;
					rn-=ln;
					l++;
					ln=a[l].n;
					lc=a[l].c;
					//cout<<ans<<"***"<<endl;
				}
			}
		}
		else
		{
			l++,r--;
			ln=a[l].n,rn=a[r].n;
			lc=a[l].c,rc=a[r].c;
		}
	}
	cout<<ans;
	return 0;
 } 
