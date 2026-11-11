#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500002],f[300002],b[500002],cnt;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		cnt=0;
		memset(b,0,sizeof(b));
		for (int j=i;j<=n;j++){
			for (int k=1;k<=cnt;k++){
				if (b[k]==a[j]){
					cnt=k-1;
					break;
				}
			}
			b[++cnt]=a[j];
		}
		for (int j=1;j<=cnt;j++){
			f[b[j]]++;
		}
	}
	for (int i=1;i<=m;i++){
		cout<<f[i]<<" ";
	}
	return 0;
} /*
4 3
1 2 1 3
10 3
3 1 2 1 3 2 3 1 2 1
*/ 
