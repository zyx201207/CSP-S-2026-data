#include <bits/stdc++.h>
using namespace std;

const int MAXN(2E5+5);
int a[MAXN];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n]<<endl;
		return 0;
	}
	if(m==n){
		int ans(a[1]);
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans<<endl;
	}
	int ans(a[n]);
	for(int i=n-1;i>=n-m;i--){
		ans=ans&a[i];
	}
	cout<<ans<<endl;
	return 0;
}