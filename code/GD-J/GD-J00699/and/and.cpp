#include<bits/stdc++.h>
using namespace std;
int n,a[200005],ans[200005],maxa,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	ans[0]=a[0];
	for(int k=0;k<m-1;k++){
		for(int j=0;j<n;j++){
			ans[j]=ans[j]&a[j];
			maxa=max(maxa,ans[j]);
		}
	}
	cout<<maxa;
	return 0;
}
