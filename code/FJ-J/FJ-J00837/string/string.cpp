#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,p,t;
ll a[200005];
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	bool falg=false;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		if(b[i]!=b[i-1]){
			falg=true;
		}
		m+=a[i];
	}
	if(falg==false){
		cout<<"0";
		return 0;
	}
	p=m;
	m=ceil(m/2.0);
	ll p=m;
	ll op=1;
	while(p>0){
		p-=a[op];
	    op++;
	}
	t=1;
	ll y=n;
	ll k=0;
	ll u=0;
	while(u<m){
		if(t>op){
			k+=a[y];
			break;
		}
		if(y<op){
			k+=a[t];
			break;
		}
		if(b[y]!=b[t]){
			if(a[y]>a[t]){
				u+=a[t];
				a[y]-=a[t];
				k+=a[t];
				t++;
			}else{
				if(a[y]<a[t]){
					u+=a[y];
					y--;
					k+=a[y];
					a[t]-=a[y];
				}else{
					if(a[y]==a[t]){
						u+=a[y];
						t++;
						y--;
						k+=a[y];
					}
				}
			}
		}else{
			if(a[y]>a[t]){
				u+=a[t];
				t++;
				a[y]-=a[t];
			}else{
				if(a[y]<a[t]){
					u+=a[y];
					y--;
					a[t]-=a[y];
				}else{
					u+=a[y];
					y--;
					t++;
				}
			}
		}
	}
		cout<<k;
	return 0;
}
/*
2
2 a
3 a 
*/
