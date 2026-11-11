#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5+5;
int n , m , a[N];
ll last[N] , nxt[N] , en[N];
ll cnt[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0) , cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i] , cnt[i] = 1;
	
	for(int i = n;i >= 1;i--){
		if( last[a[i]] ) nxt[i] = last[a[i]];
		else nxt[i] = i+1 , en[a[i]] = i;
		last[ a[i] ] = i;
	}
	for(int i = 1;i <= n;i++)
		cnt[ nxt[i] ] += cnt[i];
	for(int i = 1;i <= m;i++) cout << cnt[ en[i] ] << " ";
	return 0;
}
/*
4 3
1 2 1 3
ans £º
3 1 4 
10 3
3 1 2 1 3 2 3 1 2 1
ans:
10 3 3
*/
