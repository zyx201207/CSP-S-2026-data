#include<bits/stdc++.h>
using namespace std;
vector<char> a;
int ans=0;
void str(int n,int m)
{
	if(n<m)
	{
		if(a[n]==a[m]) return str(n+1,m-1);
		else
		{
			a[m]=a[n];
			ans++;
			return str(n+1,m-1);
		}
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int b;
	long long c;
	char d;
	cin>>b;
	for(int i=0;i<b;i++)
	{
		cin>>c>>d;
		while(c>0){a.push_back(d);c--;}
	}
	str(0,a.size()-1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
