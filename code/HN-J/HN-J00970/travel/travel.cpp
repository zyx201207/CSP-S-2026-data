#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cx,cy,sx,sy;
	bool sum[10]={0};
	cin>>cx>>sx>>cy>>sy;
	if(sx==sy){
		cout<<"0000";
		return 0;
	}if(cx==cy){
		sum[1]==1;
		if(sx.substr(0,2)==sy.substr(0,2)){
			sum[2]==1;
			if(sx.substr(2,3)<"D"&&sy.substr(2,3)<"D"){
				sum[3]==1;
				if(sx.substr(2,3)>="D"&&sy.substr(2,3)>="D"){
					cout<<"1111";
					return 0;
				}
				if((sx.substr(2,3)<="B"&&sy.substr(2,3)<="B")||(sx.substr(2,3)>="B"&&sy.substr(2,3)>="B")){
					sum[4]==1;
				}else{
					cout<<"1110";
					return 0;
				}
			}else{
				cout<<"1100";
				return 0;
			}
		}else{
			cout<<"1000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	if(sum[1]==sum[2]==sum[3]==sum[4]==1){
		cout<<"1111";
	}
	return 0;
}
