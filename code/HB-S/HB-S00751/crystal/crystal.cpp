#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500100];
int ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(n==1){
		ans=1;
	}
	if(n==2){
		if(m>=a[1]-a[0]) ans=2;
	}
	if(n>2){
		for(int i=0;i<n;i++){
			m=m-(a[n/2]-a[i]);
			if(a[i]==a[i-1]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
