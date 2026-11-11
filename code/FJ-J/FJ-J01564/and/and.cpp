#include<bits/stdc++.h>
using namespace std;
int n,m,a[10000],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-1;i++){
		for (int j=i+1;j<=n;j++){
			if((a[i]&a[j])>ans){
				ans=(a[i]&a[j]);
			}
		}
	}
	cout<<ans;
	return 0;
}
