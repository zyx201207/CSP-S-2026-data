#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans;

int main(){
	freopen("and","r",stdin);
	freopen("and","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(ans<(a[i]&a[j])){
				ans=a[i]&a[j];
			}
		}
	}
	cout<<ans;
	return 0;
}
