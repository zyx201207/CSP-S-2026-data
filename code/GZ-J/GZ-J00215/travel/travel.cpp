//GZ-J00215    贵州省瓮安第二中学    卢浩宇
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string cr,sr,cx,sx;
bool pan(int n){
	if(sr[2]=='A'||sr[2]=='B'||sr[2]=='C'){
		if(sx[2]=='A'||sx[2]=='B'||sx[2]=='C'){
			cout<<1;
			return true;
		}else {
			cout<<0<<0;
			return false;
		}
	}else if(sr[2]=='F'||sr[2]=='D'){
		if(sx[2]=='F'||sx[2]=='D'){
			cout<<1;
			return true;
		}else{
			 cout<<0<<0;
			 return false;
		}
	}
}
void paan(int n){
	if(sr[2]=='A'){
		if(sx[2]=='B'){
			cout<<1;
		}else cout<<0;
	}else if(sr[2]=='B'){
		if(sx[2]=='A'||sx[2]=='C'){
			cout<<1;
		}else cout<<0;
	}else if(sr[2]=='C'){
		if(sx[2]=='B'){
			cout<<1;
		}else cout<<0;
	}else if(sr[2]=='D'){
		if(sx[2]=='F'){
			cout<<1;
		}else cout<<0;
	}else if(sr[2]=='F'){
		if(sx[2]=='D'){
			cout<<1;
		}else cout<<0;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx){
		cout<<1;
		if(sr[0]==sx[0]&&sr[1]==sx[1]){
	    	cout<<1;
	    	if (pan(0)){
	    		paan(0);
			}
    	}else{
    		cout<<0<<0<<0;
    	}
	}else{
		cout<<0<<0<<0<<0;
	}
	return 0;
} 
