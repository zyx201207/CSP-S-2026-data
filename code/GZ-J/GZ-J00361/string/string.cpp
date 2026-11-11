//¿ÓºŒ‘∆ GZ-J00361 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
const int N=2E5+10;
ll n,a[N],l,r,x,y,cnt,z,w,ans;
char c[N],d;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    r=n;
    for(ll i=1;i<=n;i++){
    	cin>>a[i]>>c[i];
    	cnt+=a[i];
	}
	w=cnt;
	d=c[r];
	y=a[r];
	while(1){
		l++;
		z+=a[l];
		x=a[l];
		while(x){
			if(r<=l){
				cout<<ans<<endl;
				return 0;
			}
			if(y){
				cnt-=min(y,x);
				if(d!=c[l]){
					ans+=min(y,x);
				}
				ll yy=y;
				y=max(y-x,0ll);
				x=max(x-yy,0ll);
				if(cnt<=w/2+(w%2)){
					cout<<ans<<endl;
					return 0;
				}
				if(cnt<=z){
					cout<<ans<<endl;
					return 0;
				}
			}
			else{
				r--;
				if(r==l){
					break;
				}
				y=a[r];
				d=c[r];
			}
		}
		if(r<=l){
			cout<<ans<<endl;
			return 0;
		}
	}
	cout<<ans<<endl;
    return 0;
}
