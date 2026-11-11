#include<bits/stdc++.h>
using namespace std;
int c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2; 
	if(c1=c2){
		cout<<"1";
		cout<<"1";
		cout<<"1";
		if(c2-c1==1 && c1-c2==1){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}
	if(c1!=c2){
		cout<<"0000";
	}
	return 0;	
}
