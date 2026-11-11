#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[1000+5];
	cin>>n>>m;
	int b;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]==0)b=a[i];
		if(a[i]>b)b=a[i];
	}
	cout<<b;
	return 0;
}
