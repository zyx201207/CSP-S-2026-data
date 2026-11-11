#include <bits/stdc++.h>
using namespace std;
int main(){
	string ca,cb,cc,cd,n;
	cin>>ca>>cb>>cc>>cd;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	if(ca==cc){
		n="1";
		if(cb[0]==cd[0]&&cb[1]==cd[1]){
			n+="1";
			if(cb[2]==65){
				if(cd[2]==66 || cd[2]==67){
					n+="1";
				}
			}else if(cb[2]==66){
				if(cd[2]==65 || cd[2]==67){
					n+="1";
				}
			}else if(cb[2]==67){
				if(cd[2]==65 || cd[2]==66){
					n+="1";
				}
			}else if(cb[2]==68&&cd[2]==70){
				n+="1";
			}else{n="1100";}
		}else{n="1000";}
	}else{n="0000";}
	if(cb[2]==66){
		if(cd[2]==67||cd[2]==65){
			n+="1";
		}
	}if(cd[2]==66){
		if(cb[2]==65||cb[2]==67){
			n+="1";
		}
	}if(cb[2]==66&&cd[2]==67){
		n+="1";
	}else if(cb[2]==65||cb[2]==67){
		if(cd[2]==66){n+="1";}
	}else if(cb[2]==68&&cd[2]==70){
		n+="1";
	}else if(cb[2]==68&&cd[2]==70){
		n+="1";
	}else{n+="0";} 
	cout<<n;
	return 0;
}
