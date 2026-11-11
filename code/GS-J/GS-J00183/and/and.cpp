#include<bits/stdc++.h>
using namespace std;
struct k{
	int x;
	int w;
	char z;
};
k r;k x;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r.x>>r.w>>r.z;
	cin>>x.x>>x.w>>x.z;
	int c,d;
	if(r.x==x.x){
		cout<<1;
	}else{
		cout<<0;
	}
	
	if(r.w==x.w&&r.x==x.x){
		cout<<1;
	}else{
		cout<<0;
	}
		
	c=max(r.z,x.z);
	d=min(r.z,x.z);
	if(r.w==x.w&&r.x==x.x){
		if(c-1==d||c-2==d){
			if(c!=68&&d!=67){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}

	
	if(r.w==x.w&&c<=67){
		if(c-1==d){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(r.w==x.w&&c==70&&d==68){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
