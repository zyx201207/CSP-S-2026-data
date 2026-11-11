#include <bits/stdc++.h>
using namespace std;
long long num[1005],n,p,m,answer[1005];
int a[1005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	
	for (int i = 1;i <= n;i++){
		cin >> num[i];
	}
	for (int i = 1;i <= n;i++){
		p = i;
		
		for (int j = i;j <= n;j++){
			a[num[j]]++;
			if (a[num[j]] > 1) {
				for (int h = p;h <= j;h++){
					if (num[h] == num[j]){
						p = h+1;
						for (int o = 1;o <= p-1;o++){
							a[num[p-o]]--;
						}
						}
					}
				}
			}
			for (int h = p;h <= n;h++){
				answer[num[h]]++;
			}
		}
	
	
	for (int i = 1;i <= m;i++)
	cout << answer[i] << " ";
	return 0;
}
