#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e5+5;
int n,a[N],sum,ans;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	int cnt=sum/2,id;
	for(int i=1;i<=n;++i){
		if(cnt>=a[i])cnt-=a[i];
		else{
			id=i;
			break;
		}
	}
	int x=0,sx=0,y=0,sy=0;
	if(cnt){
		x=id;
		sx=cnt;
		if(sum%2){
			if(a[id]-cnt-1>0){
				y=id;
				sy=a[id]-cnt-1;
			}
			else{
				y=id+1;
				sy=a[y];
			}
		}
		else{
			if(a[id]-cnt>0){
				y=id;
				sy=a[id]-cnt;
			}
		}
	}
	else{
		x=id-1;
		sx=a[x];
		if(sum%2){
			if(a[id]>=2){
				y=id;
				sy=a[id]-1;
			}
			else{
				y=id+1;
				sy=a[y];
			}
		}
		else{
			y=id;
			sy=a[id];	
		}
	}
	while(x>=1&&y<=n){
		if(c[x]==c[y]){
			if(sx==sy){
				x--;
				y++;
				sx=a[x];
				sy=a[y];
			}
			else if(sx>sy){
				sx-=sy;
				y++;
				sy=a[y];
			}
			else{
				sy-=sx;
				x--;
				sx=a[x];
			}
		}
		else{
			if(sx==sy){
				ans+=sx;
				x--;
				y++;
				sx=a[x];
				sy=a[y];
			}
			else if(sx>sy){
				ans+=sy;
				sx-=sy;
				y++;
				sy=a[y];
			}
			else{
				ans+=sx;
				sy-=sx;
				x--;
				sx=a[x];
			}
		}
	}
	cout<<ans;
	return 0;
}
