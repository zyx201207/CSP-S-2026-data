//GZ-S00360  遵义第四中学 颜嘉成 
#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int n,a[MAXN],m,tmp[3][MAXN],ans; 
int d[MAXN];
int baol(int x){
	int m1=m,ans1=0;
	for(int i=1;i<=n;i++){
		d[i]=a[i]-x;
	}
	sort(d+1,d+n);
	for(int i=1;i<=n;i++){
		if(d[i]<=0&&m1+d[i]>=0){ans1++;m1+=d[i];}
		else ans=max(ans1,ans);
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	for(int i=1;i<=n;i++){
		baol(a[i]);
	}
	cout<<ans;
	return 0;
}
