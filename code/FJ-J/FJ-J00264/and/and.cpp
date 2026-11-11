#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long maxa=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxa=(maxa,a[i]);
		}
		cout<<maxa;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			maxa=max(maxa,a[i]&a[j]);
		}
	}
	cout<<maxa;
	return 0;
}

