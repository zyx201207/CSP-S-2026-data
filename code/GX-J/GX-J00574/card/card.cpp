#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,o=0,ands,zong=0;
	cin >> n >> m;
	int a[n],b[n],c[10];
	for (int i=0;i<=n;i++){
		cin >> a[i];
	}
	while (b[1]==0){
		for (int i=0;i<=n;i++){
			b[i-ands] = a[i];
			if(i<=2){
			for (int j=i;j>=0;j--){
				if (b[j]==b[i]){
					for (int at=0;at<=n;at++){
						b[at]==0;
					}
					ands=i+1;
					b[1]=b[i];
					break;
			}
			}
			}
		for (int rt=n;rt>=0;rt--){
			c[b[i]-1]++;
			}
		}
	}
	for (int i=0;i<=10;i++){
		if (c[i]!=0){
			cout << c[i];
			}
	}
	return 0;
	}
