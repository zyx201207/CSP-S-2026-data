#include<bits/stdc++.h>
using namespace std;
int a[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cr,sr,cx,sx;
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx) a[1]=1;
	if(sr[0]==sx[0]&&sr[1]==sx[1]){
		a[2]=1;
		if(sr[2]=='A'||sr[2]=='B'||sr[2]=='C'){
			if(sx[2]=='A'||sx[2]=='B'||sx[2]=='C') a[3]=1;
		}
		else if(sr[2]=='D'||sr[2]=='F'){
			if(sx[2]=='D'||sx[2]=='F') a[3]=1;
		}
	}
	if(a[1]==1&&a[3]==1){
		if(sr[2]=='A'){
			if(sx[2]=='B') a[4]=1;
		}
		else if(sr[2]=='B'){
			if(sx[2]=='A'||sx[2]=='C') a[4]=1;
		}
		else if(sr[2]=='C'){
			if(sx[2]=='B') a[4]=1;
		}
		else if(sr[2]=='D'){
			if(sx[2]=='F') a[4]=1;
		}
		else if(sr[2]=='F'){
			if(sx[2]=='D') a[4]=1;
		}
	}
	for(int i=1;i<5;i++){
		cout<<a[i];
	}
	return 0;
}
