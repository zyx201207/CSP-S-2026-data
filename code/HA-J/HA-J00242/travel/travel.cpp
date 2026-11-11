#include<bits/stdc++.h>
using namespace std;
int x,y;
bool bx,by;
string cx,cy,sx,sy;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cx>>sx>>cy>>sy;
	if(cx!=cy){
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<2;i++){
		x=x*10+(sx[i]-'0');
		y=y*10+(sy[i]-'0');
	}
	if(x!=y){
		cout<<"1000";
		return 0;
	}
	if(sx[2]=='D'||sx[2]=='F') bx=1;
	if(sy[2]=='D'||sy[2]=='F') by=1;
	if(bx!=by){
		cout<<"1100";
		return 0;
	}
	if(bx==1){
		cout<<"1111";
		return 0;
	}
	if(abs(sx[2]-sy[2])==1){
		cout<<"1111";
		return 0;
	} 
	cout<<"1110";
	return 0;
}
