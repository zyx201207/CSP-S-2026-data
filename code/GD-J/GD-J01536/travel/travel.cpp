#include<bits/stdc++.h>
using namespace std;
string sr,sx;
int cr,cx;
int pr,px;char lr,lx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx){ //chexiang
		cout<<1;
	}
	else if(cr!=cx){
		cout<<0;
	}
	pr=(sr[0]-'0')*10+sr[1]-'0';
	lr=sr[2];
	px=(sx[0]-'0')*10+sr[1]-'0';
	lx=sx[2];
	if(pr==px){  //pai
		cout<<1;
		if(lr=='A'||lr=='B'||lr=='C'){ //ce
			if(lx=='A'||lx=='B'||lx=='C'){
				cout<<1;
				if(abs(lr-lx)==1){
	                cout<<1;
	            }
	            else{
		            cout<<0;
	            }
			}
			else{
				cout<<0;
			}
		}
		else if(lr=='D'||lr=='F'){
			if(lx=='D'||lx=='F'){
				cout<<1;
				if(abs(lr-lx)==1){
	                cout<<1;
	            }
	            else{
		            cout<<0;
	            }
			}
			else{
				cout<<0;
			}
		}
	}
	return 0;
}
