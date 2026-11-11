#include<bits/stdc++.h>
using namespace std;
int a[200007];
int ans=0;
int n,m;
int awy(int x,int y){
	int l=0,h=1;
	while(x>0&&y>0){
		int a=x%2,b=y%2;
		if(a==1&&b==1)l+=h;
		x=x/2,y=y/2;
		h*=2;
	}
	return l;
}
void dfs(int start,int x,int s){
	cout<<start<<endl;
	if(s>=m){
		int h=awy(x,a[start]);
		ans=max(h,ans);
		cout<<x<<' '<<h<<endl;
		return;
	}
	for(int i=start+1;i<=n;i++){
		dfs(i,awy(x,a[i]),s+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out ","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==1){
		cout<<a[1];
		return 0;
	}
	for(int i=1;i<=n-m+1;i++)dfs(i,a[i],1);
	cout<<ans<<"\n";
	return 0;
}
