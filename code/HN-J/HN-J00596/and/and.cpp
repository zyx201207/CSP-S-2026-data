#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int shu[1001]={ };
	int a[1001]={ },num[1001]={ };
	for(int i=1;i<=n;i++){
		cin >> a[i];
		for(int j=1;j<=a[i];j++){
			a[i]=a[i]%2;
			num[i]=a[i];
		}
		for(int k=a[i];k>0;k--){
			cout << num[k];
		}
		cout << num[i] << " ";
	}
	return 0;
}
