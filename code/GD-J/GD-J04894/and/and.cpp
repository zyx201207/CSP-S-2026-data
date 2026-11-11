#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[1100],maxx,c[1100];
void f(long long ans,int m){
	if(m==0){
		maxx=max(maxx,ans);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!c[i]){
			c[i]=1;
			f(ans&a[i],m--);
			c[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		c[i]=1;
		f(a[i],m-1);
		c[i]=0;
	}
	cout<<maxx;
	return 0;
}
