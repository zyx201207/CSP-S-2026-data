#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin>>m>>n;
	int num[n];
	for(int i=0;i<n;i++)
	cin>>num[i];
	int b=0;
	for(int i=0;i<n-1;i++)
	{
		if(num[i] and num[i+1]>b)
		b=num[i] and num[i+1];
	}
	cout<<m<<endl;
	return 0;
}
