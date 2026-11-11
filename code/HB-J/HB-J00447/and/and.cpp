#include<bits/stdc++.h>
using namespace std;
int n,m,a[100009]={0},ma=0;
void f(int x,int ans,int cnt){
	if(x>n){
		if(cnt==m){
			ma=max(ma,ans);
		}
		return ;
	}
	if(cnt==0){
		f(x+1,a[x],1);
		f(x+1,0,0);
	}
	f(x+1,ans&a[x],cnt++);
	f(x+1,ans,cnt);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	f(1,0,0);
	cout<<ma;
	return 0;
}
