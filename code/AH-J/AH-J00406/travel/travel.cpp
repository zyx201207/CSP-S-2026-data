#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int Rc=c1[0]*10+c1[1];
	int Xc=c2[0]*10+c2[1];
	if(Rc==Xc){
		cout<<"1";
		int Rp=s1[0]*10+s1[1];
		int Xp=s2[0]*10+s2[1];
		if(Rp==Xp){
			cout<<"1";
			int R=s1[2]-'A'+1;
			int X=s2[2]-'A'+1;
			int x,y;
			if(R>3){
				x=1;
			}
			if(R<=3){
				x=0;
			}
			if(X>3){
				y=1;
			}
			if(X<=3){
				y=0;
			}
			if(x==y){
				cout<<"1";
				int Min=min(R,X);
				int Max=max(R,X);
				if(Min+1==Max){
					cout<<"1"<<endl;
					return 0;
				}
				else{
					cout<<"0"<<endl;
					return 0;
				}
			}
			else{
				cout<<"00"<<endl;
				return 0;
			}
		}
		else{
			cout<<"000"<<endl;
			return 0;
		}
	}
	else{
		cout<<"0000"<<endl;
		return 0;
	}
}
