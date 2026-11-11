#include<bits/stdc++.h>
using namespace std;
int main{
	freopen(“card.in”,“r”,stdin);
	freopen(“card.out”,“w”,stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5],ans[n+5];
	for(int i = 1,i <= n,i++){
		cin >> a[i];
	}
	for(int j = 1,j <= n,j++){
		for(int q = 1,q <= n,q++){
			if(a[q]==a[j]){
				for(int x = j,x <= q,x++){
					delete a[x];
					ans[x]++;
				}
			}
		}
	}
	for(int p = 1,p <= n,p++){
		cout << ans[p];
	}
	return 0;
}	