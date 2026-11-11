#include<bits/stdc++.h>
using namespace std;
#define ll long long
string r,rr,x,xx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>r;
	cin>>rr;
	cin>>x;
	cin>>xx;
	if(r==x){
		cout<<"1";
			if(rr[0]==xx[0]){
		if(rr[1]==xx[1]){
			cout<<"1";
				if(rr[2]=='A'||rr[2]=='B'||rr[2]=='C'){
		if(xx[2]=='A'||xx[2]=='B'||xx[2]=='C'){
			cout<<"1";
			if(rr[2]+1=='D'||rr[2]-1=='C'||xx[2]+1=='D'||xx[2]-1=='C'){
				cout<<"0";
			}else if(rr[2]+1==xx[2]||rr[2]-1==xx[2]){
				cout<<"1";
			}
		}else if(xx[2]=='D'||xx[2]=='F'){
			cout<<"0";
			cout<<"0";
		}
	}
	if(rr[2]=='D'||rr[2]=='F'){
		if(xx[2]=='D'||xx[2]=='F'){
			cout<<"1";
			if(rr[2]+1=='D'||rr[2]-1=='C'||xx[2]+1=='D'||xx[2]-1=='C'){
				cout<<"0";
			}else if(rr[2]+1==xx[2]||rr[2]-1==xx[2]){
				cout<<"1";
			}
		}else if(xx[2]=='A'||xx[2]=='B'||xx[2]=='C'){
			cout<<"0";
			cout<<"0";
		}
	}
		}else{
			cout<<"0";
			cout<<"0";
			cout<<"0";
		}
	}

	}else{
		cout<<"0";
		cout<<"0";
		cout<<"0";
		cout<<"0";
	}

	
	return 0;
}
