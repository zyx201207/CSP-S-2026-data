//GZ-J00631 六盘水市第二十四中学 廖国吉 
#include<bits/stdc++.h>
using namespace std;
struct dd{
	char a[2][3];
};
char xr,xx;
int main(){
	dd r,x;
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	    cin>>r.a[1][1]>>r.a[1][2]>>r.a[2][1]>>r.a[2][2]>>r.a[2][3];
		cin>>x.a[1][1]>>x.a[1][2]>>x.a[2][1]>>x.a[2][2]>>x.a[2][3];
		if(r.a[1][1]==x.a[1][1]&&r.a[1][2]==x.a[1][2]) cout<<1;
		else cout<<0;
		if(r.a[2][1]==x.a[2][1]&&r.a[2][2]==x.a[2][2]) cout<<1;
		else cout<<0;
		xr=r.a[2][3];
		xx=x.a[2][3];
		if(xr=='B'||xr=='A'||xr=='C'){
			if(xx=='B'||xx=='A'||xx=='C') cout<<1;
			else cout<<0;
		}
		else if(xr=='D'||xr=='F'){
			if(xx=='D'||xx=='F') cout<<1;
			else cout<<0;
		}
		if(xr=='B'||xr=='A'||xr=='C'){
			if(xr=='A'&&xx=='B') cout<<1;
		    else if(xr=='B'&&xx=='A') cout<<1;
		    else if(xr=='B'&&xx=='C') cout<<1;
		    else if(xr=='C'&&xx=='B') cout<<1;
		    else cout<<0;
		}
		else if(xr=='D'||xr=='F'){
			if(xr=='A'&&xx=='B') cout<<1;
			else if(xr=='A'&&xx=='B') cout<<1;
			else cout<<0;
		}
		else cout<<0;
	return 0;
}
