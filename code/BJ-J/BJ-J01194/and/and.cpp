#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,maxx=-1,ans=0;
	cin>>n>>m;
	if(n==1){
		cout<<0;
		exit(0);
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=n;j>=1;j--){
			ans=(a[i]&a[j]);
			if(ans>=maxx)
				maxx=ans;
		}
	}
	cout<<maxx;
	return 0;
}
