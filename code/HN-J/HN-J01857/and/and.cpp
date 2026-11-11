#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[201010];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	if(m==1){
		cout<<a[n];
		return 0;
	}else if(m==2){
		bool b=0;
		int x;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i-1;j++){
				int po=a[i]&a[j];
				x=max(x,a[j]);
			}
		}
		cout<<x;
		return 0;
	}else if(m==n){
		int x=a[1];
		for(int i=1;i<=n;i++){
			x=x&a[i];
		}cout<<x;
		return 0;
	}int yu=0;
	for(int i=1;i<=n;i++){
		if(a[i]=i-1)yu++;
	}
	if(yu==n){
		int op=a[n]&a[n-1];
		cout<<op;
		return 0;
	}int ans=a[n],aq=0;
	for(int i=n;i>=1;i--){
		aq++;
		ans=ans&a[i];
		if(aq==m)break;
	}cout<<max(ans,1ll);
	return 0;
}

