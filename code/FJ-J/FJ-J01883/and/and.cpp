#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001];
int ans;
bool f=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=4)f=0;
	}if(n==m){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}cout<<ans;
		return 0;
	}if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}cout<<ans;
		return 0;
	}if(f==1){
		sort(a+1,a+n+1,cmp);
		ans=a[1];
		for(int i=2;i<=m;i++){
			ans&=a[i];
		}cout<<ans;
		return 0;
	}
	return 0;
}
