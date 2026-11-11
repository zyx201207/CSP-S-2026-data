#include <bits/stdc++.h>
using namespace std;
long long a[200005],n,m,maxa=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==2){
		for(int i=1;i<=n-m+1;i++){
			for(int j=i+1;j<=n;j++){
				maxa=max(maxa,a[i]&a[j]);
			}
		}
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxa=max(maxa,a[i]);
		}
	}
	if(m==n){
		maxa=a[1];
		for(int i=2;i<=n;i++){
			maxa=maxa&a[i];
		}
	}
	cout<<maxa;
	return 0;
}
