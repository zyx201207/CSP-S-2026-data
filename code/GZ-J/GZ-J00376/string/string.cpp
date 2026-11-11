//GZ-J00376 喻东志 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
long long n;
long long num;
char word;
long long number;
string s;
string s_op;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>num>>word;
		while(num!=0)
		{
			s+=word;
			num--;
		}
	}
	int len=s.length();
	for(int i=0;i<len;i++)
	{
		s_op[i]=s[len-i-1];
	}
	for(int i=0;i<len/2;i++)
	{
		if(s[i]!=s_op[i]) number++;
	}
	cout<<number<<'\n';
	return 0;
}
