#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[512345],f[312345];
int s[512345];
int b[312345],c[312345];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++){
		int sum=0;
		memset(b,0,sizeof b);
		for(int j=i;j<=n;j++){
			if(b[a[j]]){
				for(int k=c[a[j]]+1;k<=sum;k++) b[s[k]]=0;
				sum=c[a[j]];
			}
			else b[a[j]]=1,c[a[j]]=++sum,s[sum]=a[j];
		}
		for(int i=1;i<=sum;i++) f[s[i]]++;
	}
	for(int i=1;i<=m;i++) cout << f[i] << " ";
	return 0;
}
