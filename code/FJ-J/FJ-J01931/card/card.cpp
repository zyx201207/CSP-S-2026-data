#include <bits/stdc++.h>
using namespace std;
int a[501], n, m, b[501], l, c[301];
bool flag=1;
int fl[500001];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	//ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]<a[i-1])flag=0;
	}
	if(flag){
		for(int i=1; i<=m-1; i++) cout<<"0 ";
	cout<<m;
	}
	else {
		for(int i=1; i<=n;i++ ){
			memset(fl, 0, sizeof(fl));
		//	memset(b, 0, sizeof(b));
			l=i-1;
			for(int j=i; j<=n; j++) {
				if(fl[a[j]]>0) l=fl[a[j]], fl[a[j]]=j;
				else fl[a[j]]=j;
			}
			for(int j=l+1; j<=n; j++) {
				c[a[j]]++;
			}
		}
		for(int i=1; i<=m; i++) cout<<c[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
