#include <iostream>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,x=0,a[200005];
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(a[j]<a[j-1])
			{
				x=a[j];
				a[j]=a[j-1];
				a[j-1]=a[j];
			}
		}
	}
	cout << a[m];
}
