#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,a[20000005],mx=0,ans=0,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int q=a[i]&a[i+1];
		if(q>=ans)ans=q;
	}
	mx=ans;
	for(int j=2;j<=m;j++){
		for(int i=1;i<=n;i++){
			int q=a[i]&mx;
			if(q>=ans)ans=q;
		}
		mx=ans;
	}
	cout<<ans;
	
	return 0;
} 
