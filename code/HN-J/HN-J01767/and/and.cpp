#include <bits/stdc++.h>
using namespace std;
#define int long long
int an[100000+10];
int awy(int n,int m){
	int s=0,t=0,ws=0,sw=0;
	while(n){
		s=s*10+(n%2);
		n/=2;
		ws++;
	}
	while(m){
		t=t*10+(m%2);
		m/=2;
		sw++;
	}
	int p=0;
	if(ws>sw){
		int o=10;
		for(int i=1;i<=ws-1;i++) o=o*10;
		while(s){
			if(s/o%10==t/o%10){
				p=p*10+1;
			}
			else{
				p*10;
			}
			o*=10;
		}
	}
	else{
		int o=10;
		for(int i=1;i<=sw-1;i++) o=o*10;
		while(s){
			if(s/o%10==t/o*10){
				p=p*10+1;
			}
			else{
				p*10;
			}
			o*=10;
		}
	}
	int o=10;
	int q=0;
	while(p){
		q++;
		p/=o;
	}
	int js=0,sz=1;
	for(int i=0;i<q;i++){
		if(i==0){
			js+=1;
			continue;
		}
		for(int j=1;j<=i;j++){
			sz=sz*2;
		}
		js+=sz;
	}
	return js;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>an[i];
	int l=1,r=n,mx=-1;
	while(l<n){
		if(r==l){
			r=n;
			l++;
		}
		mx=max(mx,awy(an[l],an[r]));
		r--;
	}
	cout<<mx;
	return 0;
}
