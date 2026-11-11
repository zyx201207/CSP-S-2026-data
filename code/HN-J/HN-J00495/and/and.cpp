#include<bits/stdc++.h>
using namespace std;
int n,m,maxn=0;
int a[1000005];
int cmp(int x,int y){
	return x>y;
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp); 
	int ans=a[1];
	for(int j=2;j<=m;j++){
		ans&=a[j];
	}
	cout<<ans;
	return 0;
}
