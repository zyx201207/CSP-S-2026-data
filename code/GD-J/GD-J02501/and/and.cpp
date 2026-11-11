#include<bits/stdc++.h>
using namespace std;
int a[200005];int n,m,ans;
void f(int x,int y,int z){
	if(y==m){
		ans=max(ans,x);
		return;
	}
	if(z==n)return;

	if(y==0){
		f(a[z],y+1,z+1);
		f(0,0,z+1);
	}else{
	f(x&a[z],y+1,z+1);
	f(x,y,z+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	int q=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		q=max(q,a[i]);
	}
	if(m==1)cout<<q;
	f(0,0,0);
	cout<<ans;
	return 0;
}
