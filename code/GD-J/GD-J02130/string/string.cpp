#include<bits/stdc++.h>
using namespace std;
string a;
int n; 
int ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		string m;
		cin>>m;
		for(int j=1;j<=x;j++)
		{
			a+=m;
		}
	}
	//cout<<a<<endl;
	int le = a.size();
	int lele = le;
	if(le%2!=0)
		lele--;
	for(int i=0;i<lele/2;i++)
	{
		if(a[i]!=a[le-i-1])
			ans++;
	}
	cout<<ans;
	return 0;
}
