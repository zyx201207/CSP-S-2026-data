#include<bits/stdc++.h>
using namespace std;
int main(){
	char c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
	    cout<<'1';
	    if(strown(s1,1)==strown(s2,1)+1 || strown(s1,1)==strown(s2,1)-1){
		cout<<'1';
	    }else{
		cout<<'0';
	    }
	    if(int(strown(s1,2))==int(strown(s2,2)+1) || int(strown(s1,2))==int(strown(s2,2))-1){
		cout<<'1';
	    }else{
		cout<<'0';
	    }
	    if(strown(s1,2)=="C" && strown(s1,2)=="D" || strown(s1,2)=="D" && strown(s1,2)=="C"){
		cout<<'1';
	    }else{
		COUT<<'0';
	    }
	}else{
	    cout<<"0000";
	}










return 0;
}
