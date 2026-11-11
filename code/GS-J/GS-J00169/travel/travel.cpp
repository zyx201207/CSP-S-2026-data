#include<iostream>
#include<cmath>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d,e;
	cin>>a>>b>>c>>d;
	if(a==c){//同车厢 
		cout<<"1";
		if(b[0]==d[0]&&b[1]==d[1]){//同一排 
			cout<<"1";
			if(b[2]==68||b[2]==70&&d[2]==68||d[2]==70){//过道同一侧 DF
				cout<<"1";
				if(abs(((b[0]-48)*10+(b[1]-48))-((d[0]-48)*10+(d[1]-48)))==1||abs(((b[0]-48)*10+(b[1]-48))-((d[0]-48)*10+(d[1]-48)))==0){
					cout<<"1";
				}else cout<<"0";
			}else if(abs(b[2]-d[2])==1||abs(b[2]-d[2])==2){//ABC
				if(b[2]==68||b[2]==70||d[2]==68||d[2]==70){
					cout<<"0";
				}else cout<<"1";
				if(abs(((b[0]-48)*10+(b[1]-48))-((d[0]-48)*10+(d[1]-48)))==1||abs(((b[0]-48)*10+(b[1]-48))-((d[0]-48)*10+(d[1]-48)))==0){
					if(b[2]==67){cout<<"0";}else cout<<"1";
				}else cout<<"0";
			}else{
				cout<<"0";//不是过道同一侧 
				if(b[0]==d[0]&&b[1]==d[1]){//同一排 
					cout<<"1";
				}else cout<<"0";//相离 
			} 
		}else{
			cout<<"0";
			if(b[2]==d[2]){
				cout<<"1";
			}else cout<<"00";
		}
	}else cout<<"0000";
}
