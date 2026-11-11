#include <bits/stdc++.h>
using namespace std;

const int N=5e5+5;
const int M=3e5+5;
int n,m,a[N];
int nxt[N],pos[N];

int c[M],res[M];
void solve(int k){
	for(int i=1;i<=m;i++) c[i]=0;
	for(int i=k;i<=n;i++){
		if(i!=nxt[i]) i=nxt[i];
		c[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		if(c[i]){
			res[i]++;
		}
	}
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		pos[a[i]]=i;
	}
	
	for(int i=1;i<=n;i++) nxt[i]=pos[a[i]];
	
	for(int i=1;i<=n;i++) solve(i);
	
	for(int i=1;i<=m;i++) cout << res[i] << " ";
	cout << "\n"; 
	return 0;
}
