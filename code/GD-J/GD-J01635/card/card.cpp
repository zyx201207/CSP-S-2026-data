#include<bits/stdc++.h>
using namespace std;
int n, m, a[500001], cnt[300001]; 
int q[500001], l;
int main(){
	//freopen("card.in", "r", stdin);
	//freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++){
		l = 0;
		bool b[500001];
		memset(b, 0, sizeof(b));
		for(int j = i; j <= n; j++){
			if(!b[a[j]]){
				q[++l] = a[j];
				b[a[j]] = 1;
			}
			else{
				int pos;
				for(int j = 1; j <= l; j++)
					if(q[j] == a[j]){
						pos = j;
						break;
					}
				l -= (n - pos + 1);
				q[++l] = a[j];
			}
		}
		for(int j = 1; j <= l; j++)
			cnt[q[j]]++;
	}
	for(int i = 1; i <= m; i++)
		printf("%d ", cnt[i]);
}
