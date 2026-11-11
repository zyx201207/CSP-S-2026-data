#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2){        // 两张车票对应的座位是否在同一节车厢
		cout<<"1"; 
		         
		for(int i=0;i<2;++i){       //两张车票对应的座位是否在同一节车厢的同一排
			if(s1[i]!=s2[i]){
				cout<<"000";
				return 0;
			}
		}
		cout<<"1";
		
		if( (s1[2]<='C' && s2[2]>='D') || (s1[2]<='C' && s2[2]>='D') ){    //两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧
			cout<<"00";
			return 0;
		}
		cout<<"1";
		
		if( abs(s1[2]-s2[2])>1 ){     //两张车票对应的座位是否相邻
			cout<<"0"; 
			return 0;
		}else{
			cout<<"1";
		}
	}else{
		cout<<"0000";
	}
	
	return 0;
} 
