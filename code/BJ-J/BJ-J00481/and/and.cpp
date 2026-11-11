#include<bits/stdc++.h>
using namespace std;
int a[2001],ans=0;int n,m;
void fun(int x,int y,int w){
	if(y==m){
		ans=max(ans,w);
	}
	for(int i=x+1;i<=n;i++){
		if((w&a[i])>=ans){
			fun(i,y+1,w&a[i]);
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		fun(i,1,a[i]);
	}
	cout<<ans;
	return 0;
}
