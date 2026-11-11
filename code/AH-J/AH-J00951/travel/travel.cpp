#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string r1,r2,x1,x2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r1>>r2>>x1>>x2;
	if(r1==x1){//在同一节车厢
		cout<<"1";
		if(r2[0]==x2[0]&&r2[1]==x2[1]){//在同一排
			cout<<"1";
			char chr=r2[2],chx=x2[2];
			bool f=0;
			if(chr=='A'&&(chx=='B'||chx=='C')){//在过道同一侧
				cout<<"1";
				f=1;
				if(chx=='B'){//在同一侧
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			if(chr=='B'&&(chx=='A'||chx=='C')){//在过道同一侧
				cout<<"1";
				f=1;
				cout<<"1";//在同一侧
			}
			if(chr=='C'&&(chx=='B'||chx=='A')){//在过道同一侧
				cout<<"1";
				f=1;
				if(chx=='B'){//在同一侧
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			if(chr=='D'&&chx=='F'){//在过道同一侧
				cout<<"1";
				f=1;
				cout<<"1";//在同一侧
			}
			if(chr=='F'&&chx=='D'){//在过道同一侧
				cout<<"1";
				f=1;
				cout<<"1";//在同一侧
			}
			if(f==0){//不在过道同一侧
				cout<<"00";
			}
		}
		else{//不在同一排
			cout<<"000";
		}
	}
	else{//不在同一节车厢
		cout<<"0000";
	}
	return 0;
}
