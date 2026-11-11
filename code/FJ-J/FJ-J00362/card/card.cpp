#include <bits/stdc++.h>
using namespace std;
int a[500005],c[500005],d[500005],s=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	for (int i=1;i<=n;i++){
		for (int j=i;j<n;j++){
			if (a[j]!=a[j+1]){
				if (s%2) d[j]++;
				s=0;
			}
			else s++; 
		}
		for (int i=1;i<=n;i++){
			d[i]=0;
		}
	}
	for (int i=1;i<=n;i++){
		if (d[i]) cout << d[i]<< " ";
	}
	return 0;
}
