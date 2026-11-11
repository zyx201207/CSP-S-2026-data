#include<bits/stdc++.h>
using namespace std;
int n,m,ans,ff,maxx;
bool f[200005];
int a[200005];
void cho(int x,int y){
	for(int i=y;i<=n-m+x;i++){
		if(x==1) ff=i;
		if(f[i]==0){
			ans=(ans&a[i]);
			f[i]=1;
		}
		if(x+1<=m) cho(x+1,i+1);
		else{
			if(maxx<ans) maxx=ans;
			ans=a[ff]; 
		}
		f[i]=0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	ans=a[1];
	cho(1,1);
	cout<<maxx;
	return 0;
}
