#include<bits/stdc++.h>
#define int long long
using namespace std;
string car1,seat1;
string car2,seat2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);cout.tie(NULL);
	cin>>car1>>seat1>>car2>>seat2;
	if(car1==car2){
		cout<<"1";
		if(seat1[0]==seat2[0]&&seat1[1]==seat2[1]){
			cout<<"1";
			if((seat1[2]<='C'&&seat2[2]<='C')||(seat1[2]>='D'&&seat2[2]>='D')){
				cout<<"1";
				if(abs(seat1[2]-seat2[2])==1)
					cout<<"1";
				else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
