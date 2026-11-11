#include <bits/stdc++.h>
using namespace std;
long long n,m,nlz[100005],p=1,c,a,i=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> nlz[i];
	}
	sort(nlz+1,nlz+n+1);
	for(int j=1;j<=m;j++){
		if(nlz[i]==nlz[i+1]){
			p++;
			a++;
			i++;
		}
		else {
			nlz[i]++;
			c += p;
		}
		if(c>m){
			break;
		}
	}
	cout << a+1;
	return 0;
}
