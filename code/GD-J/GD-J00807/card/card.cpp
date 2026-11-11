#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],ans[N],s[N],p[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int ok=1;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		if (a[i]<a[i-1]){
			ok=0;
		}	
	} 
	if (n<=5 && m==1){
		cout << n;
		return 0;
	}else if (n<=5 && m==2){
		int x,b,a1,b1,sum1,sum2;
		a[1]=a1;
		for (int i=1;i<=n;i++){
			if (a[i]!=a[1]){
				b1=a[i];
				break;
			}
		}
		for (int i=1;i<=n;i++){
			for (int j=i;j<=n;j++){
				if (a[i]==a1) x++;
				else b++;
			}
			if (x>=1) sum1++;
			if (b>=1) sum2++;
		}
		cout << sum1 << " " << sum2;
	}else if (ok==1){
		for (int i=1;i<=n;i++){
			for (int j=i;j<=n;j++){
				if (a[j]==a[j-1] && j!=i){
					continue;
				}else{
					p[a[j]]++;
				}
			}
		}
		for (int i=1;i<=m;i++) cout << p[i] << " ";
		return 0;
	}else{
		for (int i=1;i<=n;i++){
			cout << i << " ";
		}
		return 0;
	}
	return 0;
}
