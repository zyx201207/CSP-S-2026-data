#include <bits/stdc++.h> 
using namespace std;
int n,m,a1,a2,a3;
int a[200],b[200];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		a[i]=b[i];	
	}
	cout<<a1<<' '<<a2<<' '<<a3;
	return 0;
}
