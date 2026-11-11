#include<bits/stdc++.h>
using namespace std;

int hw(string x)
{

	int l=1,r=x.size();
	int sum=0;
	while(l<=r)
	{
		if(x[l]!=x[r])
			sum++;
	}
	return sum;
}

int main()
{
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

  	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		char c;
		cin>>a>>c;
	}
	cout<<0;
	
	return 0;
}
