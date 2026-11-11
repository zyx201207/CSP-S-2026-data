#include <bits/stdc++.h>
using namespace std;
const int N=1e+8;
int n,m,a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(m==1){
	cout<<a[1];
	}
	else{
	if(m==2){
	int ans=0;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<n;j++){
			ans=max(ans,a[i]&a[j]);
		}
	}
	cout<<ans;
	}
	else{
	if(m==n){
	int ans=a[1];
	for(int i=2;i<=n;i++){
		ans=ans&a[i];
	}
	cout<<ans;
	}
	else{
	if(m==n-1){
	int ans=0;
	for(int i=1;i<=n;i++){
		int anss=111111111;
		for(int j=1;j<=n;j++){
			if(j!=i){
				anss=anss&a[j];
			}
		}
		ans=max(anss,ans);
	}
	cout<<ans;
	}
	else{
	cout<<a[m];
	}
	}
	}
	}
	return 0;
}

