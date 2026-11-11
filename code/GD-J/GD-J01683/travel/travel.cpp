#include<bits/stdc++.h>
using namespace std;
string cx,sx,cy,sy;
string ans;
string cntx,cnty;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cx>>sx>>cy>>sy;
	if(cx==cy) ans+='1';
	else ans+='0';
	for(int i=0;i<sx.size()-1;i++){
		cntx+=sx[i];
		cnty+=sy[i];
	}
	if(cntx==cnty&&cx==cy) ans+='1';
	else ans+='0';
	if(cntx==cnty&&cx==cy&&((sx[2]>='A'&&sx[2]<='C'&&sy[2]>='A'&&sy[2]<='C')||(sx[2]>='D'&&sx[2]<='F'&&sy[2]>='D'&&sy[2]<='F'))) ans+='1';
	else ans+='0';
	if(ans=="111"&&(sx[2]+1==sy[2]||sy[2]+1==sx[2])) ans+='1';
	else ans+='0';
	cout<<ans;
	return 0;
}
