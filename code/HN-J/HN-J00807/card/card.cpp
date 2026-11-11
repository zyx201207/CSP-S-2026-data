#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m,a[500005],si[500005],cnt=0;
	cin >> n >> m;
	for(int i = 0;i<=n;i++){
		cin >> a[i] >> a[i+1] >> a[i+2];
	}
	for(int i=1;i<=n;i++)
	{
		si[i] = i;
		for(int j = i;j<=n;j++)
		{
			if(a[j] == a[i])
			{
				a[i] = 0;
				a[i+1] = a[j];
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}

