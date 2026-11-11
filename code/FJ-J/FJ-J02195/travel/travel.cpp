//
#include<bits/stdc++.h>
using namespace std;

string c_1,c_2,c_3,c_4;
char a,b;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c_1>>c_2>>c_3>>c_4;
//	cout<<c_1<<c_2<<c_3<<c_4<<'\n;';
//	cout<<c_1==c_3;
// cout<<(c_2[2]-64)/4;
// cout<<c_1<<'\n'<<c_2<<'\n'<<c_3<<'\n'<<c_4<<'\n';
	if(c_1==c_3){
		cout<<1;
		if(c_2.substr(0,2)==c_4.substr(0,2)){
			cout<<1;
			if((c_2[2]-64)/4==(c_4[2]-64)/4){
				cout<<1;
				if(abs(c_2[2]-c_4[2])==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
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
