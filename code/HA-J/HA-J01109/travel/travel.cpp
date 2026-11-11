#include <bits/stdc++.h>
using namespace std;
int main( ){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	char s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(s1>=18)cout<<"0000";
	if(s2>=18)cout<<"0000";
	
	if(c1==s1)cout<<"1";
	else{
		cout<<"0";
	}
	if(c1==s1 && c2==s2) cout<<"1";
	else{
		cout<<"0";
	}
	if(c1 = s1 && c2 = s2 || s1 = "A" s2 = "B" || s1 = "A" s2 = "C" || s1 = "C" s2 = "A" || s1 = "B" s2 = "A" || s1 = "B" s2 = "C" || s1 = "D" s2 = "F" || s1 = "F" s2 = "D" ){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(s1= "A" s2= "B" || s1= "B" s2= "A" ||s1= "B" s2="C" ||s1= "C" s2= "B" || s1= "D" s2= "F" || s1= "F" s2= "D"){
		cout<<"1";
	}
	else{
		cout<<"0";
}
return 0;
}
