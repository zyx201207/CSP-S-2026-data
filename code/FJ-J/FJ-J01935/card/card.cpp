#include<bits/stdc++.h>
using namespace std;
int n, m, d, a[200002], nu[100002], ans[100002];

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		scanf("%d", &a[i]);}
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			if (nu[a[j]]==0){
				nu[a[j]]=++d;}
			else{
				d=nu[a[j]];
				for (int k=1;k<=m;k++){
					if (nu[k]>d)nu[k]=0;}}}
		for (int k=1;k<=m;k++){
			if (nu[k]>0)ans[k]++;
			nu[k]=0;}
		d=0;}
	for (int k=1;k<=m;k++){
		cout << ans[k] << " ";}
	return 0;
}

