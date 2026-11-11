#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[10001],b[1001];
	for (int i = 1;i<=n;i++){
		cin >> a[i];
	}
	for (int i = 1;i<=n;i++){
		int s[100001];
		int mk[10001] = 0;
		for (int j = i;j<=n;j++){
			if (a[j]!=0){
				s[j] = a[j];
				if (mk[a[j]]==0){
					b[s[j]]++;
					mk[a[j]] = 1;
				}
				for (int k = i;k<j;k++){
					
					if(a[k]==a[j]){
						for(int h = k;h<j;h++){
							a[h] = 0;
						}
					}
					
				}
				
			}
		}
	}
	for (int i = 1;i<=m;i++){
		cout << b[i] << " ";
	}
	return 0;
}
