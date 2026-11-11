#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,c3,c4;
	int a=0,s=0,d=0,f=0,g,h;
	cin>>c1>>c2>>c3>>c4;
	if(c1!=c3) {
		cout<<"0000";
		return 0;
	} else {
		a=1;
		if(c2[0]==c4[0]) {
			if(c2[1]==c4[1]) {
				s=1;
				g=int(c2[2]);
				h=int(c4[2]);
				if(g-h==1||g-h==-1) {

					if(c2[2]!='C'&&c4[2]!='D') {
						if(c2[2]!='D'&&c4[2]!='C') {
							d=1;
							f=1;
							cout<<"1111";
							return 0;
						}
					}

				} else {
					if(g-h==2||g-h==-2) {
						if(c2[2]=='A'&&c4[2]=='C') {
						
							
								
										cout<<"1110";
										return 0;

									
							
								

							
						}else{
							if(c2[2]=='C'&&c4[2]=='A'){
							
										cout<<"1110";
										return 0;
	
							}
						}
					}
					cout<<"1100";
					return 0;
				}
				cout<<"1100";
				return 0;



			} else {
				cout<<"1000";
				return 0;
			}

		} else {
			cout<<"1000";
			return 0;
		}


	}
}



