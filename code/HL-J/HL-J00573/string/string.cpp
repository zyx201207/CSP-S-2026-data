#include<bits/stdc++.h>
using namespace std;
int dp[1009][1009];
int diff(string a,string b)
{
	size_t i;
	long long cnt=0;
	if(a.size()!=b.size()) cout<<"Error"<<endl;
	for(i=0;i<a.size();i++)
	{
		if(a[i]!=b[i]) cnt++;
	}
	//cout<<i<<endl;
	return cnt;
}
void odd(string s,size_t size)
{
	string a=s.substr(0,size/2);
	string b=s.substr(size/2+1);
	reverse(b.begin(),b.end());
//	cout<<a<<endl<<b<<endl; 
	cout<<diff(a,b)<<endl;
}
void even(string s,size_t size)
{
	string a=s.substr(0,size/2);
	string b=s.substr(size/2); 
	reverse(b.begin(),b.end());
//	cout<<a<<endl<<b<<endl;
	cout<<diff(a,b)<<endl;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	while(n--)
	{
		int tem;
		char c;
		cin>>tem>>c;
		for(int i=1;i<=tem;i++) s+=c;
	}
	//cin>>s;
	size_t size=s.size();
	if(size%2==1) odd(s,size);
	else even(s,size);
	//cout<<s.size();
}
