#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3){
		cout<<"1";
		if(c2[0]==c4[0]&&c2[1]==c4[1]){
			cout<<"1";
			int a1=c2[2]-'A'+1,a2=c4[2]-'A'+1;
			if(a1<=3&&a1>=1&&a2<=3&&a2>=1){
				cout<<"1";
				if(a1-a2==1||a2-a1==1)cout<<1;
				else cout<<"0";
			}
			else if(a1>=4&&a1<=5&&a2>=4&&a2<=5){
				cout<<"11";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else{
		cout<<"0000";
	}
	return 0;
} 
