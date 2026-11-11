#include<bits/stdc++.h> 
using namespace std;
long long n,a[1000000],t=0;
char c[1000000];
string s;
bool hwc(string x)
{
	int len=x.size();
	for(int i=0;i<len;i++)
		if(x[i]!=x[len-1-i])
			t++;
	if(t!=0)
		return false;
	else
		return true;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)
			s+=c[i];
	}
	if(hwc(s))
		cout<<"0";
	else
		cout<<t/2;
	return 0;
}
