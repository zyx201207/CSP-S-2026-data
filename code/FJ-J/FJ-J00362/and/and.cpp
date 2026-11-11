#include <bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[100005],s=-1;
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	if (m==n){
		for (int i=2;i<=n;i++){
			a[1]&=a[i];
		}
		cout << a[1];
	}
	else if(m==1){
		for (int i=1;i<=n;i++){
			s=max(s,a[i]);
		}
		cout << s;
	}
	else if (m==2){
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				s=max(s,a[i]&a[j]);
			}
		}
		cout << s;
	}
	else cout << 1;
	return 0;
}

