#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in",in,"r",stdin);
	freopen("travel.out",out,"w",stdout);
    bool c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if (c1==c2){
    	cout<<"11";
	}else{
		cout<<"00";
	}
	
	
	if (s1-s2==1){
		cout<<"11"<<endl;       
	}else if(s1-s2>0){
		cout<<"00"<<endl;
	}else{
		cout<<"10"<<endl;
	}
	return 0;
}
