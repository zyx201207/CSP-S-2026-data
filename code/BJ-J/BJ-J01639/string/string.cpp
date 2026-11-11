#include<bits/stdc++.h>
using namespace std;
int a[200005];
string c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	int n,q;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
		q+=a[i];
	}
	//~ cout<<s;
	q=q-1;
	int l=q/2;
	//~ cout<<" "<<l<<" "<<q;
	int cnt=0;
	if(q%2==0)
	{
		int i=0;
			for(int j=q-1;j>=l;j--)
			{
				if(s[i]!=s[j])
				{
					cnt++;
				}
				i++;
			}
	}
	else{
		int i=0;
			for(int j=q-1;j>l;j--)
			{
				if(s[i]!=s[j])
				{
					cnt++;
				}
				i++;
			}
	}
	cout<<cnt;
	return 0;
}
