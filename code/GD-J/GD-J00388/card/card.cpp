#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[500005];
int b[500005];
int z[500005];
int z_end=0;
int s[300005];
int v[300005];
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <=n; ++i) {
		cin >> a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	bool fl = true;
	for (int i=1; i<=n;++i){
		if (b[i]!=a[i]) {
			fl = false;
			break;
		}
	}
	if (fl==true) {
		int th=1;
		for (int i=1;i<=n;++i){
			if (a[i]!=a[i+1]){
				cout<<th << " ";	
			}
		    ++th;
		}
		cout<<"\n";
		return 0;
	}
	for (int i = 1;i <=n; ++i) {
	    fill(s+1,s+m+1,0);
	    z_end=0;
	    for (int j = i; j <=n; ++j) {
	    	if (s[a[j]]) {
	    		for (int k=s[a[j]]+1; k<=z_end;++k){
	    			s[a[k]]=0;
	    			z[k]=0;
				}
				z_end=s[a[j]];
			} else {
				z[++z_end]=a[j];
				s[a[j]]=z_end;
			}
		}
		for (int j = 1;j<=z_end; ++j) {
			++v[z[j]];
		}
	}
	for (int i = 1; i<=m;++i){
		cout << v[i]<< " ";
	}
	cout<<"\n";
}
