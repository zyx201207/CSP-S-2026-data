#include<bits/stdc++.h> 
using namespace std;
string s[1000010];
int n,a;
string c;
int main(){
    int cnt=0;
    cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		cnt+=a;
	}
	for(int i=1;i<=cnt;i++)
	{
		s[i]=c;
	}
	string p[1000010],q[1000010];
	for(int i=1;i<=cnt/2;i++)
	{
		p[i]=s[i];
	}
	for(int i=cnt;i>cnt/2;i--)
	{
		q[i]=s[i];
	}
	if(p==q)
	{
		cout<<"0";
		return 0;
	}
	int cnta;
	for(int i=1;i<=cnt/2;i++)
	if(p[i]!=q[i])
	{
		cnta++;
	}
	cout<<cnta;
    return 0;
}
