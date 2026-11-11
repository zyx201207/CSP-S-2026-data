#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans=-1,x,y,z;
bool c=true;
void dfs(int d,int t,int s){
	if(t==m){
		ans=max(ans,s);
		return;
	}
	for(int i=d+1;i<=n-m+t+1;i++){
		dfs(i,t+1,s&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==3) x++;
		else if(a[i]==2) y++;
		else if(a[i]==1) z++;
		if(a[i]>3) c=false;
	}
	if(c){
		if(x>=m) ans=3;
		else if(x+y>=m) ans=2;
		else if(x+z>=m) ans=1;
		else ans=0;
	}
	else if(m==n) for(int i=n;i>0;i--) ans&=a[i];
	else if(n<=2000||m==n-1||m==1) dfs(0,0,2147483647);
	else{
		sort(a+1,a+n+1);
		ans=a[n];
		for(int i=n-1;i+m>n;i--) ans&=a[i];
	}
	cout<<ans;
	return 0;
}
