#include<bits/stdc++.h>
using namespace std;

int n,m;
long long ans=1,a[200010];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}
	else{
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
	}
	return 0;
}

