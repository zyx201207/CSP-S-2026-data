#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
int n, m, cnt;
int a[N];
struct node{
	bool p;
	int d;
};
node f[N];
int b[N];
int c[N];
void check(int x){
	if(f[x].p){
		int tnt = cnt;
		for(int j = f[x].d + 1;j <= tnt;j++){
			f[b[j]].p = 0;
			f[b[j]].d = 0;
			b[j] = 0;
			cnt--;
		}
		return ;
	}
	else{
		b[++cnt] = x;
		f[x].d = cnt;
		f[x].p = 1;
		return ;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		memset(f, 0, sizeof(f));
		memset(b, 0, sizeof(b)); 
		for(int j = i;j <= n;j++){
			check(a[j]);
		}	
		for(int j = 1;j <= cnt;j++){
			c[b[j]]++;
		}
	}
	for(int i = 1;i <= m;i++){
		cout << c[i] << " ";
	}
	return 0;
}
