#include<bits/stdc++.h>
using namespace std;
int n,m,l,r;
char c,ce;
bool fa(char a,char b){
	if(a=='A'||a=='B'||a=='C'&&(b=='A'||b=='B'||b=='C')){
		return true;
	}else if(a=='D'||a=='E'&&(b=='D'||b=='E')){
		return true;
	}else{
		return false;
	}
}
bool fb(char a,char b){
	if(c=='A'&&ce=='B'){
		return true;
	}else if(c=='B'&&(ce=='A'||ce=='C')){
		return true;
	}else if(c=='C'&&ce=='B'){
		return true;
	}else if((c=='D'&&ce=='E')||(c=='E'&&ce=='D')){
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>l>>c>>m>>r>>ce;
	if(n==m){
		cout<<1;
		if(l==r){
			cout<<1;
			if(fa(c,ce)){
				cout<<1;
				if(fb(c,ce)){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} /*
02 01A 03 01A
*/
