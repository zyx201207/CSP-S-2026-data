#include <bits/stdc++.h>
using namespace std;
int a[100005];
int cnt[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,c=1;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		int b[100005]={0};
		for(int j=1;j<i;j++){
			b[j]=b[i]-a[j];
		}
	}
	return 0;
}



