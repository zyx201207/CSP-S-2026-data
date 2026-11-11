#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s2,c3,s4;
	int ok1=0,ok2=0,ok3=1,ok4=0;
	cin>>c1>>s2>>c3>>s4;
	if(c1==c3){
		ok1=1;
	}
	
	if(s2[0]==s4[0] && s2[1]==s4[1]){
		ok2=1;
	}
	char a=s2[2],b=s4[2];
	int a1=a,b1=b;
	if(ok2==1){
		if(a1==67 && b1==68){
			ok3=0;
		}
		if(a1==68 && b1==67){
			ok3=0;
		}
	}
	if(ok3!=0){
		if(a1-b1==1 || b1-a1==1){
			ok4=1;
		}
	}
	if(ok1==0){
		ok2=0;
		ok3=0;
		ok4=0;
	}
	if(ok2==0){
		ok3=0;
		ok4=0;
	}
	cout<<ok1<<ok2<<ok3<<ok4;
	return 0;
}
