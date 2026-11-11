#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,l,r,a[200005],ans,p,wl,wr;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	} 
	l=0;r=n+1;p=0;wl=0;wr=0;
	while(l<r){
		if(wl==wr){
			p=wl;wl+=a[++l];wr+=a[--r];
			if(c[l]!=c[r]){
				if(wl<=wr){
					ans+=wl-p;
				}
				else if(wl>wr){
					ans+=wr-p;
				}
			}
		}
		else if(wl>wr){
			p=wr;wr+=a[--r];
			if(c[l]!=c[r]) ans+=min(wl,wr)-p;
		}
		else if(wl<wr){
			p=wl;wl+=a[++l];
			if(c[l]!=c[r]) ans+=min(wl,wr)-p;
		}
	}
	cout<<ans;
	return 0;
}
