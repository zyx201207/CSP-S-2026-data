#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
			int d;
	cin>>d;
	long long max=0;
	int l;
	char a;
	string w;
	long long s=0;
	
	for(int i=0;i<d;i++)
	{
		cin>>l;
		cin>>a;
		s=s+l;
		for(int j=0;j<l;j++)
		{
			w=w+a;
		}
		
	}
		
	cout<<w;
	long long sx=s/2;
	
		for(int i=0;i<=sx-1;i++)
		{
			if(w[i]!=w[s-i-1])
			max++;
		}

	cout<<max;
}


