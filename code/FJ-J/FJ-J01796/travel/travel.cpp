#include<bits/stdc++.h>
using namespace std;
string cr,sr,cx,sx;
int a[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>cr>>sr>>cx>>sx;
	int trar=(cr[0]-'0')*10+cr[1]-'0';
	int trax=(cx[0]-'0')*10+cx[1]-'0';
	int pr=(sr[0]-'0')*10+sr[1]-'0';
	int px=(sx[0]-'0')*10+sx[1]-'0';
	if(trar==trax){
		a[1]=1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(pr==px){
		a[2]=1;
	}else{
		cout<<a[1]<<"000";
		return 0;
	}
	if(('A'<=sr[2]&&sr[2]<='C'&&'A'<=sx[2]&&sx[2]<='C')||('D'<=sr[2]&&sr[2]<='F'&&'D'<=sx[2]&&sx[2]<='F')){
		a[3]=1;
	}else{
		cout<<a[1]<<a[2]<<"00";
		return 0;
	}
	if((sr[2]+1==sx[2]&&sx[2]!='D')||(sr[2]=='D'&&sx[2]=='F')||(sx[2]=='D'&&sr[2]=='F')||(sx[2]+1==sr[2]&&sr[2]!='D')){
		a[4]=1;
	}else{
		a[4]=0;
	}
	for(int i=1;i<=4;i++){
		cout<<a[i];
	}
	return 0;
} 
