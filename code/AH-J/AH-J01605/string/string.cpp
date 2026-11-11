#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,x[N];
char k[N];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>k[i];
		for(int j=1;j<=x[i];j++)
		{
			s+=k[i];
		}
	}
	int cnt=0,len=s.size();
	for(int i=0,j=len-1;i<j;i++,j--)
	{
		if(s[i]!=s[j])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
