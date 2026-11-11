#include<bits/stdc++.h>
using namespace std;
string a,b,a1,b1;
char t,t1;
int l,p,c,ll;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>a1>>b1;
	if(a==a1){
		l=1;
	}
	if(b[0]+b[1]==b1[0]+b1[1] && l==1){
		p=1;
	}
	t=b[2];
	t1=b1[2];
	if(t<='C' && t1<='C' && p==1){
		c=1;
	}else if(t>='D' && t1>='D' && p==1){
		c=1;
	}
	int aa=(int)t;
	int bb=(int)t1;
	if(c==1){
		if(aa-bb==1){
			ll=1;
		}else if(bb-aa==1){
			ll=1;
		}
	}
	cout<<l<<p<<c<<ll;
	return 0;
}
