#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	string cr,sr,cx,sx;
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}long long s_size=sr.size();
	for(long long i=0;i<s_size-1;i++){
		if(sr[i]!=sx[i]){
			cout<<"000";
			return 0;
		}
	}cout<<1;
	if(sr[2]=='A'){
		if(sx[2]=='B'){
			cout<<11;
			return 0;
		}if(sx[2]=='C'){
			cout<<10;
			return 0;
		}cout<<"00";
		return 0;
	}if(sr[2]=='B'){
		if(sx[2]=='A'||sx[2]=='C'){
			cout<<11;
			return 0;
		}cout<<"00";
		return 0;
	}if(sr[2]=='C'){
		if(sx[2]=='B'){
			cout<<11;
			return 0;
		}if(sx[2]=='A'){
			cout<<10;
			return 0;
		}cout<<"00";
		return 0;
	}if(sr[2]=='D'){
		if(sx[2]=='F'){
			cout<<11;
			return 0;
		}cout<<"00";
		return 0;
	}if(sr[2]=='F'){
		if(sx[2]=='D'){
			cout<<11;
			return 0;
		}cout<<"00";
		return 0;
	}
	return 0;
}
