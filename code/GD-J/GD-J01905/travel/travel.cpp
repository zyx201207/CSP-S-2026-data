#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int r_xiang,x_xiang;
	string r_zuo,x_zuo;
	cin>>r_xiang>>r_zuo>>x_xiang>>x_zuo;
//	cout<<r_xiang<<r_zuo<<x_xiang<<x_zuo;
	if(r_xiang==x_xiang){
		cout<<"1";
		if(r_zuo[0]==x_zuo[0] && r_zuo[1]==x_zuo[1]){
			cout<<"1";
//			cout<<r_zuo[0]<<" "<<x_zuo[0]<<" "<<r_zuo[1]<<" "<<x_zuo[1];
			char a='A',b='B',c='C',d='D',e='E';
			if(r_zuo[2]==a || r_zuo[2]==b || r_zuo[2]==c && x_zuo[2]==a || x_zuo[2]==b || x_zuo[2]==c){
				cout<<"1";
				if(r_zuo[2]==x_zuo[2] || r_zuo[2]==x_zuo[2]-1 || r_zuo[2]==x_zuo[2]+1){
					cout<<"1";
					return 0;
				}else{
					cout<<"0";
				}
			}else if(r_zuo[2]==d || r_zuo[2]==e && x_zuo[2]==d || x_zuo[2]==e){
				cout<<"11";
				return 0;
			}
			else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	
	
	return 0;
}
