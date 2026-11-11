#include <bits/stdc++.h>
using namespace std;
#define LL long long

LL const MAXN = 1e6 + 10;

LL n, m;
LL a[MAXN];
LL ans[MAXN];
LL acc[MAXN]; 
LL cnt[MAXN];
bool LOL[MAXN];
LL fff[MAXN];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)cin >> a[i];
	
	for(int i = n; i >= 1; i--){
		memset(cnt, 0, sizeof(cnt));
		memset(LOL, false, sizeof(cnt));
		LL top = 0;
		for(int j = i; j <= n; j++){
			if(!cnt[a[i]])acc[++top] = a[i], cnt[a[i]] = top;
			else top = cnt[a[i]];
		}
		for(int j = 1; j <= top; j++){
			LOL[acc[j]] = true;
		}
		for(int j = 1; j <= top; j++){
			if(LOL[acc[j]])fff[acc[j]]++;
		}
	}
	for(int i = 1; i <= m; i++)cout << fff[i] << " "; 
	
	
	return 0;
 }  
