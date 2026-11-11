#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	char x3,x4;
	string x1,x2;
	if(c1==c2){
		cout<<'1';
		for(int i=0;i<3;i++){
			if(s1[i]>='0' && s1[i]<='9')
				x1+=s1[i];
			if(s2[i]>='0' && s2[i]<='9')
				x2+=s2[i];
		}
		if(x1==x2){
			cout<<'1';
			x3=s1[2];
			x4=s2[2];
		}else{
			cout<<"000"<<endl;
			return 0;
		}
		if((x3=='F' && x4=='D') || (x3=='D' && x4=='F') || (x3=='A' && x4=='B') || (x3=='A' && x4=='C') || (x3=='B' && x4=='A') || (x3=='B' && x4=='C') || (x3=='C' && x4=='A') || (x3=='C' && x4=='B')){
			cout<<'1';
		}else{
			cout<<"00"<<endl;
			return 0;
		}
		int o=0,z=0;
		if(x3=='F') o=5;
		if(x3=='D') o=4;
		if(x3=='C') o=3;
		if(x3=='B') o=2;
		if(x3=='A') o=1;
		if(x4=='F') z=5;
		if(x4=='D') z=4;
		if(x4=='C') z=3;
		if(x4=='B') z=2;
		if(x4=='A') z=1;
		if(abs(o-z)==1 || (abs(o-z)==2 && ((x3=='F' && x4=='D') || (x3=='D' && x4=='F')))) cout<<'1';
		else cout<<'0';	
	}
	else cout<<"0000"<<endl;
	return 0;
} 
