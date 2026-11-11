//¿ÓºŒ‘∆ GZ-S00252 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second 
#define pb push_back
#define pq priority_queue
const int N=2E6+10;
ll n,m,a[N],ans1,ans2,x,y,c[N],Min,vis1[N],vis2[N],z,l,r,c1,c2;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	z=m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=2;i<=n;i++){
		c[i]=a[i]-a[i-1];
		Min=min(Min,c[i]);
	}
	for(ll i=2;i<=n;i++){
		if(c[i]==Min&&c[i]<z){
			z-=c[i];
			ans2=2;
			y=a[i]*2;
			vis2[i]=vis2[i-1]=1;
			break;
		}
	}
	m-=(a[2]-a[1]);
	x=a[2]*2;
	ans1=2;
	vis1[1]=vis1[2]=1;
	while(m&&ans1!=n&&c1<5000){
		c1++;
		for(ll i=n;i>=3;i--){
			if(!vis1[i]&&a[i]<x){
				if(m>=x-a[i]){
					vis1[i]=1;
					m-=(x-a[i]);
					ans1++;
					x*=2;
				}
				else{
					m=0;
				}
				break;
			}
		}
		for(l;l<=n;l++){
			if(!vis1[l]){
				break;
			}
		}
		l--;
		if(x<a[l]){
			ll g=(a[l]-x+1)/2*2;
			if(m>=g){
				m-=g;
				x+=g;
			}
			else{
				break;
			}
		}
	}
	while(z&&ans2!=n&&c2<5000){
		c2++;
		for(ll i=n;i>=1;i--){
			if(!vis2[i]&&a[i]<y){
				if(z>=x-a[i]){
					vis2[i]=1;
					z-=(x-a[i]);
					ans2++;
					y*=2;
				}
				else{
					z=0;
				}
				break;
			}
		}
		for(r;r<=n;r++){
			if(!vis2[r]){
				break;
			}
		}
		r--;
		if(y<a[r]){
			ll g=(a[r]-y+1)/2*2;
			if(z>=g){
				z-=g;
				y+=g;
			}
			else{
				break;
			}
		}
	}
	cout<<max(ans1-(m<0),ans2-(z<0))<<endl;
	return 0;
}
