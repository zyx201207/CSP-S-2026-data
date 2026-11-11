#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cr,sr,cx,sx;
	cin>>cr>>sr>>cx>>sx;
	if(cr!=cx){
		cout<<"0000";
		return 0;
	}
	int r=(sr[0]-'0')*10+(sr[1]-'0');
	int x=(sx[0]-'0')*10+(sx[1]-'0');
	if(r!=x){
		cout<<"1000";
		return 0;
	}
	char r_q=sr[2];
	char x_q=sx[2];
	if((r_q=='F'||r_q=='D')&&(x_q=='F'||x_q=='D')){
		cout<<"1111";
		return 0;
	}else if((r_q=='B'||r_q=='A'||r_q=='C')&&(x_q=='B'||x_q=='A'||x_q=='C')){
		if(r_q=='A'&&x_q=='B') {
			cout<<"1111";
			return 0;
		}else if(r_q=='B'&&(x_q=='A'||x_q=='B')){
			cout<<"1111";
			return 0;
		}else if(r_q=='C'&&x_q=='B'){
			cout<<"1111";
			return 0;
		}else{	
			cout<<"1110";
			return 0;
		}	
	}else{
		cout<<"1100";
		return 0;
	}
	return 0;
}
