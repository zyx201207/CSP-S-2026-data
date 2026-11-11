#include<bits/stdc++.h>
using namespace std;
int a[10005];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	int m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	int c=a[1];
	int ans=c;
	for(int i=2;i<=m;i++){
		int b=a[i];
		ans=c and b;
	}
	cout<<ans;
	return 0;
}
