#include<bits/stdc++.h>
using namespace std;
//int a[200005];
//char na[200005];
int main()
{
	freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	long long l=0,r=0,n,i,s=0,a;
	char lname,rname,name;
	deque<pair<long long,char>> dq,t;
	//cout<<123;
	cin>>n;
	//cout<<n;
	for(i=1;i<=n;i++)
	{
		//cout<<i<<"\n";
		cin>>a>>name;
		dq.push_back({a,name});
		
	}
	while(!dq.empty())
	{
		/*t=dq;
		while(!t.empty())
		{
			cout<<t.front().first<<" ";
			t.pop_front();
		}
		cout<<endl;
		t=dq;
		while(!t.empty())
		{
			cout<<t.front().second<<" ";
			t.pop_front();
		}
		cout<<endl<<r<<endl;
		cout<<endl<<"-------"<<endl;*/
		if(l==0)
		{
			l=dq.front().first;
			lname=dq.front().second;
			dq.pop_front();
		}
		if(r==0)
		{
			if(dq.empty())
			{
				cout<<s;
				return 0;
			}
			r=dq.back().first;
			rname=dq.back().second;
			dq.pop_back();
		}
		if(lname==rname)
			l=l-min(l,r),r=r-min(l,r);
		else
		{
			//cout<<min(l,r)<<endl;
			s+=min(l,r);
			l=l-min(l,r),r=r-min(l,r);
		}
	}
	cout<<s;
}
