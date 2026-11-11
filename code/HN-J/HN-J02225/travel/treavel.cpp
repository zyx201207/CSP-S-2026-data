#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("treavel.in","r",stdin);
	freopen("treavel.out","w",stdout);
	int r=0,x=0;
	char r1,r2,r3,x1,x2,x3;
	cin>>r>>r1>>r2>>r3>>x>>x1>>x2>>x3;
    if(r==x&&r1==x1&&r2==x2&&r3==x3){
    	cout<<"1111";
	}else{
			if(r==x)
	cout<<"1";
	else{
	cout<<"0";}
	if(r1==x1&&r2==x2)
	cout<<"1";
	else{
		cout<<"0";
	}
	cout<<"11";
	}
	return 0;
}
