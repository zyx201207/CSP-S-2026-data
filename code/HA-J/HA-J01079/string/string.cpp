#include<bits/stdc++.h>
using namespace std;
vector<char> v;
stack<char> s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0,sum=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int num;
		char a;
		cin>>num>>a;
		sum+=num;
		for(int i=0;i<num;i++)
		{
			v.push_back(a);
		}
	}
	if(sum%2==0)
	{
		for(int i=0;i<sum/2;i++)
		{
			s.push(v[i]);
		}
		for(int i=sum/2;i<sum;i++)
		{
			if(s.top()==v[i]) s.pop();
			else{
				ans++;
				s.pop();
			}
		}
	}
	else{
		for(int i=0;i<(sum-1)/2;i++)
		{
			s.push(v[i]);
		}
		for(int i=(sum+1)/2;i<sum;i++)
		{
			if(s.top()==v[i]) s.pop();
			else{
				ans++;
				s.pop();
			}
		}
	}
	cout<<ans;
}
