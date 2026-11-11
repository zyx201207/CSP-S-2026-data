#include<bits/stdc++.h>
using namespace std;
string cara,sa,carb,sb,ans;
int rowa,rowb;
char seata,seatb;
int side(char x){
	if('A'<=x&&x<='C'){
		return 1;
	}else{
		return 2;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cara>>sa>>carb>>sb;
	rowa=(sa[0]-'0')*10+(sa[1]-'0');
	rowb=(sb[0]-'0')*10+(sb[1]-'0');
	seata=sa[2];
	seatb=sb[2];
	if(cara==carb){
		if(rowa==rowb){
			if(side(seata)==side(seatb)){
				if(seata>seatb){
					swap(seata,seatb);
				}
				if(seatb-seata==1){
					ans="1111";
				}else{
					ans="1110";
				}
			}else{
				ans="1100";
			}
		}else{
			ans="1000";
		}
	}else{
		ans="0000";
	}
	cout<<ans;
	return 0;
}
