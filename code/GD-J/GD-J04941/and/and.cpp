#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[200001];
void dg(int x,int y,int ns){
	if(y==3&&ns>ans) ans=ns;
	for(int i=x+1;i<=n;i++){
		dg(i,++y,ns&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
	}
	else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}
	else if(m==2){
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				if(ans<a[i]&a[j]) ans=a[i]&a[j];
			} 
		}
		cout<<ans;
	}
	else {
		ans=0;
		for(int i=1;i<=n;i++){
			dg(i,1,a[i]);
		}
		cout<<ans;
	}
	return 0;
}
