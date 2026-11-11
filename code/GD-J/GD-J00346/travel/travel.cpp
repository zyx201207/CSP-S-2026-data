#include<bits/stdc++.h>
using namespace std;

string c1,c2,s1,s2;

int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	
	bool same_car = (c1==c2);
	bool same_row = s1[0] == s2[0] && s1[1] == s2[1];
	bool same_side = s1[2]<=67 && s2[2] <= 67 || s1[2]>67 && s2[2]>67;
	bool beside = s1[2]+s2[2] == 131 || s1[2]+s2[2] == 133 || s1[2]+s2[2] ==138;
	
	if(same_car) cout<<1;
	else cout<<0;
	if(same_row && same_car) cout<<1;
	else cout<<0;
	if(same_row && same_car && same_side) cout<<1;
	else cout<<0;
	if(same_row && same_side && same_car && beside) cout<<1;
	else cout<<0;
//	if(c1==c2){
//		cout<<1;
//	}else{
//		cout<<0;
//	}
//	if(s1[0] == s2[0] && s1[1] == s2[1]){
//		cout<<1;
//		if(s1[2]<=67 && s2[2] <= 67 || s1[2]>67 && s2[2]>67){
//			cout<<1;
//		}
//		if(s1[2]+s2[2] == 131 || s1[2]+s2[2] == 133 || s1[2]+s2[2] ==138){
//			cout<<1;
//		}
//		
//	}else{
//		cout<<000;
//	}
	 return 0;
	
}
