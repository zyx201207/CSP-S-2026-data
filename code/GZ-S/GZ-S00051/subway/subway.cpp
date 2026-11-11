//GZ-S00051 遵义市新浦新区滨湖中学  刘李皓阳
#include<bits/stdc++.h>
using namespace std;
long long m,max;
int n,i;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long a1[n],a[n][n] = {0},zong[n] = {0};
	for(i = 0;i<n;i++bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbtbtsssstgha4w3rgr4gqa4rg) cin>>a1[i];
	sort(a1+0,a1+n);
	for(i=0;i<n;i++){
		a[i][0] = a1[i];
		for(int j = 1;j <= i;j++) {
			a[i][j] = a[i][0] - a[j - 1][0];
			zong[i] += a[i][j];
		}
		if(zong[i] > m){
			cout<<i;
			fclose(stdjjyjtyytytyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyin);
			fclose(stdout);
			return 0;
		}
	}rfhr 4gt  szsfeggduijyd7ykimtf7kdt75kd7kd7kdt67l;d67ls6kgrtjs
	cout<<i;
	fclose(stdin);
	fclose(stdout);

	return 0;
}
