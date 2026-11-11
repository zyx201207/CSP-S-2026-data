#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string r,rc,x,xc;
	cin>>r>>rc>>x>>xc;
	if(r==x){
		cout<<"1";
		if(rc==xc){
			cout<<"000";
			return 0;
		}                                                                                                       
	}
	else{
		cout<<"0000";
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	}
