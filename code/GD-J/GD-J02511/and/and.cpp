#include<bits/stdc++.h>
using namespace std;
int a[200001], b[200001];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; i++){
		scanf ("%d", &a[i]);
	}
	int sum = 0;
	if (m == 2){
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; i++){
			for (int j = i + 1; j <= n; j++){
				sum = max(a[j] & a[i], sum);
			}
		}
	}else{
		if (m == 3){
		
			sort(a + 1, a + n + 1);
			for (int i = 1; i <= n; i++){
				for (int j = i + 1; j <= n; j++){
					for (int k = j + 1; k <= n; k++)
						sum = max(a[j] & a[i] & a[k], sum);
				}
			}
		}else{
			if (m == 4){	
				sort(a + 1, a + n + 1);
				for (int i = 1; i <= n; i++){
					for (int j = i + 1; j <= n; j++){
						for (int k = j + 1; k <= n; k++)
							for (int l = k + 1; l <= n; l++)
								sum = max(a[j] & a[i] & a[k] & a[l], sum);
					}
				}
			}else{
				sort(a + 1, a + n + 1);
				for (int i = 1; i <= n; i++){
					for (int j = i + 1; j <= n; j++){
						for (int k = j + 1; k <= n; k++)
							for (int l = k + 1; l <= n; l++)
								for (int r = l + 1; r <= n; r++)
									sum = max(a[j] & a[i] & a[k] & a[l] & a[r], sum);
					}
				}
			}
		}
	}
	printf("%d", sum);
	return 0;
}
