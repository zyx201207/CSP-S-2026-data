#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4,s;
bool f;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3){
		s+="1";
	}else{
		s+="0000";
		cout<<s;
		return 0;
	}
	if(c2[0]==c4[0]&&c2[1]==c4[1]){
		s+="1";
	}else{
		s+="000";
		cout<<s;
		return 0;
	}
	if('A'<=c2[2]&&c2[2]<='C'&&'A'<=c4[2]&&c4[2]<='C'){
		s+="1";
	}else if('D'<=c2[2]&&c4[2]<='F'&&'D'<=c4[2]&&c4[2]<='F'){
		s+="1";
		f=1;
	}else{
		s+="00";
		cout<<s;
		return 0;
	}
	if(s=="111"){
		if(c2[2]>c4[2]){
			if((f==1&&c2[2]-c4[2]==2)||(c2[2]-c4[2]==1)){
				s+="1";
			}else{
				s+="0";
				cout<<s;
				return 0;
			}
		}else{
			if((f==1&&c4[2]-c2[2]==2)||(c4[2]-c2[2]==1)){
				s+="1";
			}else{
				s+="0";
				cout<<s;
				return 0;
			}	
		}
	}
	cout<<s;
	return 0;
}

