#include<iostream>
using namespace std;
int a[1001],b[1001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdin);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int i=1;i<=m;i++)
		{
			if(a[i]<=a[i+1])
			b[i]=a[i];
			{
				if(b[i]>=b[i+1]&&b[i]!=b[i+1]);
			}
		cout<<i;
		}
	}
	return 0;
}
