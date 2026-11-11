#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n,m;
int a[N],b[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans = 0;
	if(m==1){
		for(int i=1;i<=n;i++){
			ans = max(a[i],0);
		}
		cout<<ans<<endl;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				b[i] = a[i] & a[j];
				ans = max(b[i],0);
			}
		}
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				b[i] = a[i]&a[j];
				b[i] &= b[j];
			}
			ans = max(b[i],0);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[i] &= a[i];
			b[i] = a[i];
			a[i] &= b[i];
		}
		ans = max(a[i],0);
	}
	cout<<ans<<endl;
	return 0;
}
