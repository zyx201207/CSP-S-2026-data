#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m; cin>>n>>m;
	string s;
	int cnt=0;
	int max_num=0;
	for(long long i=0;i<n;i++)
	{
		long long num; cin>>num;
		while(num!=0)
		{
			int t=num%10;
			num/=2;
			s+=t;
		}
		for(int j=0;j<=s.size()-1;j++)
		{
			if(s[j]=='1') cnt++;
		}
		if(max_num<cnt) max_num=cnt;
		
	}
	cout<<max_num;
	return 0;      
}