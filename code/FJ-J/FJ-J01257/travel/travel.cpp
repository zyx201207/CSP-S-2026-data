#include<bits/stdc++.h>
using namespace std;
string cx,sx,cy,sy;
bool f;
void cow(char x,char y){
	char i=max(x,y);
	char j=min(x,y);
	if(f){
		if(i=='F'){
			if(j=='D'){
				f=1;
			}
			else f=0;
		}
		else if(i=='D'){
			f=0;	
		}
		else if(i-j<=2){
			f=1;
		}
		else f=0;
	}
	else f=0;
}
int ccow(char x,char y){
	char i=max(x,y);
	char j=min(x,y);
	if(f){
		if(i=='F'){
			if(j=='D'){
				cout<<1;
			}
			else cout<<0;
		}
		else if(i=='D'){
			cout<<0;
		}
		else if(i-j==1){
			cout<<1;
		}
		else cout<<0;
	}
	else cout<<0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>cx>>sx>>cy>>sy;
	if(cx==cy){
		f=1;
	}
	cout<<f;
	if(f){
		for(int i=0;i<2;i++){
			if(sx[i]==sy[i]){
				f=1;
			}
			else f=0;
		}
	}
	cout<<f;
	cow(sx[2],sy[2]);
	cout<<f;
	ccow(sx[2],sy[2]);
	return 0;
}
