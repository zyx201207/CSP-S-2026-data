/**/
#include<bits/stdc++.h>
using namespace std;
int n,m,a[20005],b[20005],maxn=0;
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+n,a+n+1);
	for(int i=n-m+1;i>=1;i--){
		int flag=0;
		for(int j=i;j<=j+m-1;j++){
			if(a[i]!=a[i+1]) flag=1;
		}
		if(flag==0){
			cout<<a[i];
		}
	}
	int ans=0;
	for(int i=n-1;i>=1;i--){
		if(a[i]%2==a[n]%2){
			ans++;
			if(ans==m) cout<<a[i];
		}
	}
	return 0;
}
