#include<bits/stdc++.h>
using namespace std;
struct node
{
	 unsigned long long sum;
	char le;
}t[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long su=0;
	long long n;
	cin>>n;
	long long l=1,r=n;
	for(long long i=1;i<=n;++i)
	{
		cin>>t[i].sum>>t[i].le;
		su+=t[i].sum;
	}
	long long mid=su%2==0?su/2:su/2+1;
//	cout<<mid<<endl;
	long long midb;
	long long ssu=0;
	for(long long i=1;i<=n;++i)
	{
		
		ssu+=t[i].sum;
		if(ssu>=mid)
		{
			midb=i;
			break;	
		}
	}
//	cout<<"*****"<<endl;
//	cout<<"**"<<mid<<" "<<midb<<" "<<t[midb].sum<<" "<<su<<" "<<ssu<<endl;
//	cout<<"*******"<<endl;
	if(su%2==0)
	{
		t[midb].sum-=min(mid-(ssu-t[mid].sum),t[mid].sum-(mid-(ssu-t[mid].sum)))*2;
	}
	else
	{
		t[midb].sum-=min(mid-(ssu-t[mid].sum),t[mid].sum-(mid-(ssu-t[mid].sum)))*2-1;
	}
	long long ans=0;
//	cout<<"**"<<mid<<" "<<midb<<" "<<t[midb].sum<<" "<<su<<" "<<ssu<<endl;
//	cout<<"*******"<<endl;
	while(1)
	{
//		cout<<"**"<<endl;
		if(t[l].le!=t[r].le)
		{
			if(t[l].sum==t[r].sum)
			{
				ans+=t[r].sum;
				l+=1;
				r-=1;
//				cout<<"**"<<endl;
			}
			else if(t[l].sum>t[r].sum)
			{
				ans+=t[r].sum;
				t[l].sum-=t[r].sum;
				r-=1;
			}
			else if(t[l].sum<t[r].sum)
			{
				ans+=t[l].sum;
				t[r].sum-=t[l].sum;
				l+=1;
			}
		}
		else
		{
			if(t[l].sum==t[r].sum)
			{
				l+=1;
				r-=1;
			}
			else if(t[l].sum>t[r].sum)
			{
				t[l].sum-=t[r].sum;
				r-=1;
			}
			else if(t[l].sum<t[r].sum)
			{
				t[r].sum-=t[l].sum;
				l+=1;
			}
		}
//		cout<<"**"<<endl;
//		cout<<l<<" "<<r<<endl;
//		cout<<t[l].sum<<" "<<t[r].sum<<endl;
		if(r<=l) break;
	}
	cout<<ans<<endl;
	return 0;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
