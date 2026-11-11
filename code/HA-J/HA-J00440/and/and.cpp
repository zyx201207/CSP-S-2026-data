#include<bits/stdc++.h>
using namespace std;
int m,n,a[200005],maxa,ans=(2e30)-1;
bool v;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(maxa,a[i]);
		ans=ans&a[i];
	}
	for(int i=1;i<=20;i++){
		int b=1;
		for(int j=1;j<=i;j++){
			b*=2;
		}
		if(a[1]==b-1){
			v=1;
			break;
		}
	}
	if(m==1){
		cout<<maxa;
	}else if(m==n){
		cout<<ans;
	}else if(m==2){
		maxa=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxa=max(maxa,a[i]&a[j]);
			}
		}
		cout<<maxa;
	}else if(m==n-1){
		maxa=0;
		for(int i=1;i<=n;i++){
			ans=(2e30)-1;
			for(int j=1;j<=n;j++){
				if(i!=j){
					ans=ans&a[j];
				}
			}
			maxa=max(maxa,ans);
		}
		cout<<maxa;
	}else if(v){
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
	}
	return 0;
}
