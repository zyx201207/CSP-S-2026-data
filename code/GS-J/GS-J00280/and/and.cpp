#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int aand(int x,int y){
	return x&y;
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	int n,m,ans;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=m+i+1;j++){
			ans=max(ans,aand(a[i],a[j]));
		}
	}
	cout<<ans;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
