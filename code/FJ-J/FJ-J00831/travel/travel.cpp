#include<bits/stdc++.h>
using namespace std;
#define int long long
int s[5];
string cr,sr,cx,sx;
int cr1,cx1,sr1,sx1,pr,px;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	for(int i=0;i<=1;i++){
		cr1=cr1*10+cr[i];
		cx1=cx1*10+cx[i];
		sr1=sr1*10+sr[i];
		sx1=sx1*10+sx[i];
	}
	if(sr[2]=='A'){
		pr=1;
	}else if(sr[2]=='B'){
		pr=2;
	}else if(sr[2]=='C'){
		pr=3;
	}else if(sr[2]=='D'){
		pr=4;
	}else{
		pr=5;
	}
	if(sx[2]=='A'){
		px=1;
	}else if(sx[2]=='B'){
		px=2;
	}else if(sx[2]=='C'){
		px=3;
	}else if(sx[2]=='D'){
		px=4;
	}else{
		px=5;
	}
	if(cr1==cx1){
		s[1]=1;
		if(sr1==sx1){
			s[2]=1;
			if((pr>=4&&px>=4)||(pr<=3&&px<=3)){
				s[3]=1;
				if(abs(pr-px)==1){
					s[4]=1;
				}
			}
		}
	}
	for(int i=1;i<=4;i++){
		cout<<s[i];
	}
	return 0;
}  
