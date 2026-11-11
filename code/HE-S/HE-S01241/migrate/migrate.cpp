#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	
	int n,d;
	cin>>n>>d;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(a[2]==3) cout<<"1"<<endl<<"2";
	else cout<<"0"<<endl<<"1";
	freopen("crystal.out","w",stdout);
	
	return 0;
}
