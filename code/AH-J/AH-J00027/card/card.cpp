#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin >> n >> k;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		}
	for(int i = 1;i <= n;i ++){
		cout << a[i] <<" ";
		}
	return 0;
}
