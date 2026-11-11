#include<bits/stdc++.h>
using namespace std;
int main(){
	freoper("travel.in","r"travel.in);
	freoper("travel.out","w"travel.ans);
	int c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	while(c1==c2&&s1==s2){
		if(c1==c2){
			cout<<1;	
		}else{
			cout<<0;
		}
		if(s1==s2){
			cout<<1;	
		}else{
			cout<<0;
		}
	}
	return 0;
}
