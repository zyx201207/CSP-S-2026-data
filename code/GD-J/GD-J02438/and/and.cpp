#include <bits/stdc++.h>
using namespace std;
const int N = 2000005;
int a[N],tmp[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	int maxn = 0;
	for(int i = 1;i<=n;i++){
		for(int j = i;j<=n;j++){
			maxn = max(maxn,(a[i])&(a[j]));
		}
	}
	cout<<maxn;
	
	
	return 0;
}
