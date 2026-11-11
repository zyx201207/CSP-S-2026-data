#include<bits/stdc++.h>
#define int long long
using namespace std;
struct zlz{
	int x;
	char y;
};
zlz a[200010];
int n,ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//Trick||Treat!
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}
	int l=1,r=n;
	while(l<r){
		int x=0,y=0;
		if(a[l].x>a[r].x&&a[l].y!=a[r].y)a[l].x-=a[r].x,x--,ans+=a[r].x;
		if(a[l].x<a[r].x&&a[l].y!=a[r].y)a[r].x-=a[l].x,y++,ans+=a[l].x;
		if(a[l].y!=a[r].y&&a[l].x==a[r].x)x--,y++,ans+=a[l].x;
		if(a[l].y==a[r].y&&a[l].x>a[r].x)a[l].x-=a[r].x,x--;
		if(a[l].y==a[r].y&&a[l].x<a[r].x)a[r].x-=a[l].x,y++;
		if(a[l].y==a[r].y&&a[l].x==a[r].x)x--,y++;
		r+=x,l+=y;
	}
	cout<<ans;
	return 0;
}


