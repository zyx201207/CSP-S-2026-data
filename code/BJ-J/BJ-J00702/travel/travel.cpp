#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int cr,ans=0,cx;
	string sr,sx;
	cin>>cr;
	cin>>sr;
	cin>>cx;
	cin>>sx;
	if(cr==cx){
		ans=1;
	}
	if(ans){
		cout<<"1111";
	}
	else{
		cout<<"0000";
	}
	return 0;
}
