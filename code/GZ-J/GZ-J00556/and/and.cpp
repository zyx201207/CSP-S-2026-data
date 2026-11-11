//GZ-J00556 ∫Œ√œ∫Ω ∫Î“„÷–—ß 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[10000000],b[1000][1000],c[1000000],h,t,x,xmax;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n;
	cin>>m;
	t=0;
	x=0;
	xmax=0;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	for(ll i=0;i<n;i++){
		h=a[i];
		while(h>0){
			h=h/2;
			t++;
		}
		c[i]=t;
		
	}
	t=0;
	for(ll i=0;i<n;i++){
		h=a[i];
		t=c[i];
		while(h>0){
			b[i][t]=h%2;
			h=h/2;
			t--;
			
		}
		
	}
	for(ll j=0;j<max(c[1],c[0]);j++){
		if(b[1][j]==b[0][j]){
			xmax++;
		}
	}
	for(ll i=1;i<n;i++){
		x=0;
		for(ll j=0;j<max(c[i],c[i-1]);j++){
			if(b[i][j]==b[i-1][j]){
				x++;
			}
		}
		
		xmax=max(xmax,x);
	}
	cout<<xmax+2;
	return 0;
} 
