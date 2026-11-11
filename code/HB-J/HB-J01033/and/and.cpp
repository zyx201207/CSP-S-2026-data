#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans=-1000000;
void f(int l,int h,int t){
	if(l==m){
		//cout<<h<<endl;
		if(ans<h) ans=h; 
		return ;
	}
	for(int i=t;i<=n;i++){
		int u;
		if(l==0) h=a[i];
		else u=h&a[i];
		//cout<<h<<" & "<<a[i]<<"="<<u<<endl;
		f(l,h,t+1);
		//cout<<u<<endl;
		f(l+1,u,t+1);
	}
}
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	f(0,0,1);
	cout<<ans;
	return 0;
}
