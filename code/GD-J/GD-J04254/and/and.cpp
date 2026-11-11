#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+7;
int a[N],b[N];
long long int n,m;
int main(){
	ios::sync_with_stdio();
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	b[0] = a[1];
	int j = 1;
	while(j!=m){
		for(int i = 1;i+1<=n;i++){
			b[i] = (a[i]&a[i+1]);
			a[i] = 0;
		}
		a[n] = 0;
		for(int i = 1;i<=n;i++){
			a[i] = b[i];
			b[i] = 0;
		}
		j++;
	}
	int maxandsum = 0;
	for(int i = 1;i<=n;i++){
		maxandsum = max(maxandsum,a[i]);
	}
	cout<<maxandsum;
	return 0;
}
