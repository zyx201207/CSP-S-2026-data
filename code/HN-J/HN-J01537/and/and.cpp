#include<bits/stdc++.h>
using namespace std;
int n,a[200003],m,ans;
void ppp(int an,int t,int u){
	if(an<=ans)return;
	if(t==m){
		ans=max(an,ans);
		return;
	}for(int i=u+1;i<n;i++){
		ppp(an&a[i],t+1,i);
	}return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)ppp(a[i],1,i);
	cout<<ans;
	return 0;
}
