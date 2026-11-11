#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,sum,x,y,xnum,ynum,tnt,ans;
string sx,sy;
struct node{
	string s;
	int num;
}a[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].s;
		sum+=a[i].num;
	}
	sum/=2;
	x=1,y=n;
	xnum=a[x].num,ynum=a[y].num;
	sx=a[x].s,sy=a[y].s;
	while(x<y){
		if(sx==sy){
			if(xnum<ynum){
				ynum-=xnum;
				x++;
				xnum=a[x].num;
				sx=a[x].s;
			}
			else if(xnum>ynum){
				xnum-=ynum;
				y--;
				ynum=a[y].num;
				sy=a[y].s;
			}
			else{
			}
		}
		else{
			if(xnum==ynum){
				ans+=xnum;
				x++,y--;
				xnum=a[x].num,ynum=a[y].num;
				sx=a[x].s,sy=a[y].s;
			}
			else if(xnum<ynum){
				ans+=xnum;
				ynum-=xnum;
				x++;
				xnum=a[x].num;
				sx=a[x].s;
			}
			else {
				ans+=ynum;
				xnum-=ynum;
				y--;
				ynum=a[y].num;
				sy=a[y].s;
			}
		}
	}
	cout<<ans;				
	return 0;
}
