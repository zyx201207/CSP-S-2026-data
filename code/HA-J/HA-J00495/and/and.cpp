#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,max=0;
	cin>>n>>m;
	int a[n];
	for(int i=1;i<=n;i++){
		cin>>a[n];
		if(a[n]>max){
			max=a[n];
		}
	}
	if(m==1)
	{
		cout<<max;
	}
	cout<<m;
	return 0;
}
