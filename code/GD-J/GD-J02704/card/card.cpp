#include <bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int main(){
	 freopen("card.in","r",stdin);
	 freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int ans = 0;
	for (int i = 1;i <= n;i ++){
		int x;
		cin >> x;
		if (a[x] != 0){
			ans ++;
			a[x] = 1;
		}
	}
	for (int i = 1;i <= n;i ++){
		for (int j = i;j = n;j ++){
			if(a[j] == 1)
			{
				b[j] ++;
			}
		}
	}
	for (int i = 1;i <= n;i++)
	{
		cout << b[j] << " ";
	}
} 
