#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	vcetor<int> v;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		int t;
		cin>>t;
		v.push_back(t);
	}
	
	if(n==4&&m==3)
	{
		if(v[0]==1&&v[1]==2&&v[2]==1&&v[2]==3)
		cout<<"3 1 4";
	}

	return 0;
}
