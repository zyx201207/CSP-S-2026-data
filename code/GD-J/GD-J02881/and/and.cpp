#include<bits/stdc++.h>
using namespace std;
int a[200001];
//
//int yu(int a,int b)
//{
//	
//}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n+1);
	cout<<a[i]-1;
	return 0;
} 
