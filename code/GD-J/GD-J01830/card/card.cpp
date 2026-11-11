#include<iostream>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[200005],num=0;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(a[j]==i)
			{
				num++;
			}
		}
		cout << num;
	}
}
