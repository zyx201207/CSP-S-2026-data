#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],mx;
int f(int x,int y){
	int now=1,ans=0;
	while(x>0&&y>0){
		if(x%2==1&&y%2==1)ans+=now;
		x/=2,y/=2,now*=2;
	}
	return ans;
}int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n-m;i++){
		int now=a[i];
		for(int j=i;j<i+m;j++)now=f(now,a[j]);
		mx=max(mx,now);
	}
	cout<<mx;
	return 0;
}
