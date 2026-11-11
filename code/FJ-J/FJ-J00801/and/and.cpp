#include<bits/stdc++.h>
using namespace std;
long long a,b,c[200007],p[77],e1,e2,d=0,o;
bool n[77],m[77];
void xox(long long q){
	bool as=0;
	long long ty=q;
	for(long long x=30;x>=0;x--){
		if(ty>=p[x]){
			if(as==0){
				e1=x;
				as=1;
			}
			ty-=p[x];
			n[x]=1;
		}else{
			n[x]=0;
		}
	}
	return;
}
long long xy(long long q,long long w){
	long long oi=0;
	xox(q);
	for(int x=0;x<=e1;x++){
		m[x]=n[x];
	}
	e2=e1;
	xox(w);
	for(int x=0;x<=min(e1,e2);x++){
		if(n[x]==1 && m[x]==1){
			oi+=p[x];
		}
	}
	return oi;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	for(int x=1;x<=a;x++){
		cin>>c[x];
		d=max(d,c[x]);
	}
	for(int x=0;x<=30;x++){
		p[x]=1;
		for(int y=1;y<=x;y++){
			p[x]*=2;
		}
	}
	if(b==1){
		cout<<d;
	}else if(b==a){
		o=xy(c[1],c[2]);
		for(int x=3;x<=a;x++){
			o=xy(o,c[x]);
		}
		cout<<o;
	}else if(b==2){
		for(int x=1;x<=a;x++){
			for(int y=x+1;y<=a;y++){
				o=max(o,xy(c[x],c[y]));
			}
		}
		cout<<o;
	}else{
		cout<<1;
	}
	return 0;
} 
