#include<bits/stdc++.h>
using namespace std;
int c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travei.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1=c2){
		if(s1=s2-1){
			cout<<"1111";
			return 0;
		}
		if(s1=s2+1){
			cout<<"1111";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
} 
