#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;

	int a,b;
	a=a2[2]-64;
	b=b2[2]-64;

	if(a1==b1) {
		cout<<"1";
		if(a2[0]==b2[0] && a2[1]==b2[1]) {
			cout<<"1";
			if((a<4&&b<4)||(a>3&&b>3)){
				cout<<"1";
				int c=abs(a-b);
				if(a<4&&b<4){
					if(c==1)cout<<"1";
					else cout<<"0";
				}else cout<<"1";
				//if(((a<4&&b<4)&&c==1)||((a>3&&b>3)&&c==1))
			}else cout<<"00";
			
		} else cout<<"000";
	}else cout<<"0000"<<endl;



	return 0;
}
