#include<bits/stdc++.h>
#define int long long
using namespace std;
int nums[200000005];
string st;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string st2;
	int cisu=0;
	for(int i=1;i<=n;i++)
	{
		cin>>nums[i]>>st;
	for(int j=1;j<=nums[i];j++)
		{
			st2+=st;
		}
	}
	int flag=st2.size()-1;
	for(int i=0;i<flag;i++)
	{
		if(st2[i]==st2[flag-i+1])
		{
			flag--;
			continue;
		}
		else
		{
			cisu++;
		}
	}
	if(cisu>st2.size()/2)
	{
		cout<<st2.size()/2;
	}
	else
	cout<<cisu;
	return 0;
}
//si=s+1-i
/*http://172.16.77.83:8888/student/*/
/*ccfloveyou*/
/*Trick||Treat!*/