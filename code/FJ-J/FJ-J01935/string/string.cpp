#include<bits/stdc++.h>
using namespace std;
long long n, a[200002], d, sum, um, m;
long long ans;
string c;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		sum+=a[i];}
	for (int i=1;i<=n;i++){
		um=a[i];
		m=0;
		if (um>=sum/2)um=sum/2;
		for (int j=n;j>0;j--){
			m+=a[j];
			if (m>=sum/2)m=sum/2;
			if (m>=um){
				n=j;
				a[n]=m-um;
				if (a[n]==0)n--;
				if (c[j]!=c[i]){
					ans+=a[i];}
				break;
			}else{
				if (c[j]!=c[i]){
					n=j;
					a[i]=um-m;
					um=um-m;
					ans+=a[j];}}}
		if (um>=sum/2)break;}
	cout << ans;
	return 0;
}
