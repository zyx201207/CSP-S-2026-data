#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,ans=0,cd=0;
	char c;
	string L="";
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a >> c;
		cd+=a;
		for(int j=1;j<=a;j++){
			L=L+c;
		}
	}
	for(int i=0;i<cd/2;i++){
		if(L[i]!=L[cd-i-1])ans++;
	}
	cout << ans << '\n';
	return 0;
}
