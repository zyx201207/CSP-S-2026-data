#include<bits/stdc++.h>
using namespace std;
int main(){

	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	
	if(c1==c3){
		c2.erase(2,2);
		c4.erase(2,2);
		if(c2==c4){
			cout<<1110;
			return 0;
		}else if(c2 != c4){
			cout<<1000;
			return 0;
		}
		return 0;
	}else if(c1!=c3){
		cout<<"0000";
		return 0;
	}
	

	return 0;
}
