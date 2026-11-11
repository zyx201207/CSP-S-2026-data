#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],ans,ans2=0,z=1,w=0;
int px(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,px);
	for(int i=n;i>=1;i--){
		if(z<a[i]){
			z*=2;
			w=0;
		}
		if(z>=a[i]){
			w++;
		}
	}
	ans=a[1];
	for(int i=2;i<=m;i++){
		ans=ans&a[i];
	}
	if(w<m){
		ans2=a[w+1];
		for(int i=w+2;i<=m+w;i++){
			ans2=ans2&a[i];
		}
	}
	cout<<max(ans,ans2);
	return 0;
} 
