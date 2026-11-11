#include<iostream>
#include<string>
#include<cmath>
using namespace std; 
using ll=long long;
const int maxn=2e5+5;
string p;
int maxlen=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int len;
		char x;
		cin>>len>>x;
		maxlen+=len;
		for(int j=1;j<=len;j++)
		{
			p+=x;
		}
	}
	int ans=0;
	int i=0,j=maxlen-1;
	for(;i<=j;)
	{
		if(p[i]!=p[j])
		{
			ans++;
		}
		i++;
		j--;
	}
	cout<<ans<<endl;
	return 0;
}

