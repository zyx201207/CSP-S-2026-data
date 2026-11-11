//GZ-J00604 遵义市新蒲中学 杨子曦
#include <bits/stdc++.h>
using namespace std;
int a[500005];
int b[300005];
int main (){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			if(a[j] < a[j+1]||j == n){
				b[a[j]]++;
			}
		}
	}
	for(int i = 1;i <= m;i++){
		cout << b[i] << " ";
	}
	return 0;
} 
