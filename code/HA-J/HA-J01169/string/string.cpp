#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char v[10000];
	int n,a,j,num=0,m=0,d=0;
	char c;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		cin>>c;
		for(j=0;j<a;j++)
		{
			v[m+j]=c;
			d+=1;
		}
		m+=j;
	}
	d--;
	cout<<d;
	for(int k=0;k<(d+1)/2;k++)
	{
		if(v[k] != v[d])
		{
			num+=1;
		}
		d--;
	}
	cout<<num;
	return 0;
}
