#include<bits/stdc++.h>
using namespace std;
vector<char> s;
long long n,cnt;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	//处理字符串 
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int num;char ch;
		cin>>num>>ch;
		for(int i=0;i<num;i++) s.push_back(ch);		 
	}
	const int L=s.size();
	if(L%2==1)//当L为奇数 
	{
		for(int i=1;i<=L/2;i++)
		{
			if(s[L/2-i]!=s[L/2+i]) cnt++; 
		} 
	}
	else//偶数 
	{
		for(int i=0;i<L/2;i++)
		{
			if(s[L/2-i-1]!=s[L/2+i]) cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
