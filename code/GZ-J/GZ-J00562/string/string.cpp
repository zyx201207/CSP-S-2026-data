//GZ-J00562，戚星汉，贵阳市白云区华师一学校 
#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,idx,idy;
long long l[N],r[N],a[N],tot,mid,ans,mov,x,y;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l[i]=tot+1;
		tot+=a[i];
		r[i]=tot;
	}
	mid=(tot+1)>>1;
	x=mid;
	y=mid;
	for(int i=1;i<=n;i++){
		if(l[i]<=mid&&mid<=r[i]){
			idx=idy=i;
			break;
		}
	}
	while(x>=1&&y<=tot){
		mov=min(x-l[idx],r[idy]-y);
		if(c[idx]!=c[idy]){
			ans+=mov;
		}
		x-=mov;
		y+=mov;
		if(x<=l[idx]&&idx>1){
			idx--; 
		}
		if(y>=r[idy]&&idy<n){
			idy++;
		}
		if(x==1&&y==tot){
			break;
		}
	}
	cout<<ans;
	return 0;
}
