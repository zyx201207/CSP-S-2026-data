#include <bits/stdc++.h>
using namespace std;
char a[100005],fa[100005];
int main(){
	freopen("string.in","r",stdin);	
	freopen("string.out","w",stdout);
	int n, cnt=1, sum=0;
	cin >>n;
	for(int i=1;i<=n;i++){
		int p;
		char q;
		cin >> p>>q;
		for(int j=1;j<=p;j++){
			a[cnt] = q;
			cnt++;
		}
	}
	for(int i=cnt;i>=1;i--){
		fa[cnt-i]=a[i];
	}
	for(int i=1;i<=cnt;i++){
		char m,n;
		m=a[i];
		n=fa[i];
		if(m !=n){
			sum++;
		}
	}
	
	cout << sum;
	return 0;
}
