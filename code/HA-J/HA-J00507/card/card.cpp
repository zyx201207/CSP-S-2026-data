#include<bits/stdc++.h>
using namespace std;

const int N = 500010;
int n, m;
int a[500010], sum[N], s[N], t[N], p[N];

int main(){
	freopen("card.in","r", stdin);
	freopen("card.out","w", stdout); 
	scanf("%d%d", &n, &m);
	bool ok = true;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		if(a[i] < a[i - 1])
			ok = false;
	}
	if(ok){
		int ans = 0;
		for(int i = 1; i <= m; i++){
			ans += a[i];
			printf("%d ", ans);
		}
		return 0;
	}
	for(int i = 1; i <= n; i++){
		memset(s, 0, sizeof(s));
		memset(t, 0, sizeof(t));
		for(int k = i + 1; k <= n; k++){
			s[a[k]]++;
			t[a[k]]++;
			if(t[a[k]] == 2){
				for(int j = p[a[k]]; j < k; j++){
					s[a[j]] = 0;
				}
			}
			else{
				p[a[k]] = k;
			}
		}
		for(int j = i + 1; j <= n; j++){
			sum[a[j]] += s[a[j]];
		}
	}
	for(int i = 1; i <= m; i++)
		printf("%d ", sum[i]);
	return 0;
}
