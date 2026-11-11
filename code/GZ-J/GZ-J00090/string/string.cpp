//GZ-J00090 ∫Œ”Í–˘
#include<bits/stdc++.h>
using namespace std;
long long n,num;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		long long x;
		cin>>x;
		char c;
		cin>>c;
		for(long long j=1;j<=x;j++)
		{
			s+=c;
		}
	}
	for(long long i=0;i<(s.size()/2);i++)
	{
		if(s[i]!=s[s.size()-i-1])
		{
			char t=s[i];
			s[i]=s[s.size()-i-1];
			s[s.size()-i-1]=t;
			num++;
		}
	}
	cout<<num;
	return 0;
}
