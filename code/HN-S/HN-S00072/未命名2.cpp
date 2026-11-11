#include<bits/stdc++.h>
using namespace std;

int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	srand(time(0));
	int n,l,r;
	cin>>n>>l>>r;
	if(l>r)
	{
		swap(l,r);
	}
	for(int i=0; i<n; i++)
	{
		cout<<rand()%(r-l+1)+l<<" ";
	}
	return 0;
}
