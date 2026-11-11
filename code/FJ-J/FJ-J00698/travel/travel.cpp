#include<bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int train1,train2;
	string a1,a2;
	cin>>train1>>a1>>train2>>a2;
	if(train1==train2){
		cout<<1;
	}else{
		cout<<0;
	}
	if((a1[0]*10+a1[1])==(a2[0]*10+a2[1])){
		cout<<1;
	}else{
		cout<<0;
	}
	int xr1=a1[0]*10+a1[1],xx1=a2[0]*10+a2[1];
	int yr1=a1[2],yx1=a2[2];
	if((a1[2]<='C'&&a2[2]<='C')||(a1[2]>='D'&&a2[2]>='D')){
	    cout<<1;
	}else{
		cout<<0;
	}
	if((xr1-1)==xx1||(xr1+1)==xx1||xr1==xx1){
		if(yr1==yx1){
			cout<<1;
		}else if((yr1-1)==yx1||(yr1+1)==yx1){
			cout<<1;
		}else{
		}
	}else{
		cout<<0;
	}
	
	return 0;
	
}

