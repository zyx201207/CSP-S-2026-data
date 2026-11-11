#include<bits/stdc++.h>
using namespace std;\
string a[2],b[2],c1,c2;
int ans[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>a[1]>>c2>>b[1];
	if(c1==c2){
		ans[1]=1;
	}else{
		cout<<"0000";
	}
	ans[2]=1;
	if((a[1]=="01A"||a[1]=="01B"||a[1]=="01C")&&(b[1]=="01A"||b[1]=="01B"||b[1]=="01C")){
		ans[3]=1;
	}else if((a[1]=="02A"||a[1]=="02B"||a[1]=="02C")&&(b[1]=="02A"||b[1]=="02B"||b[1]=="02C")){
		ans[3]=1; 
	}else if((a[1]=="04A"||a[1]=="04B"||a[1]=="04C")&&(b[1]=="04A"||b[1]=="04B"||b[1]=="04C")){
		ans[3]=1;
	}else if((a[1]=="06A"||a[1]=="06B"||a[1]=="06C")&&(b[1]=="06A"||b[1]=="04B"||b[1]=="06C")){
		ans[3]=1;
	}else if((a[1]=="08A"||a[1]=="08B"||a[1]=="08C")&&(b[1]=="08A"||b[1]=="08B"||b[1]=="08C"))ans[3]=1;else ans[3]=0;
	for(int i=1;i<=4;i++){
		cout<<ans[i];
	}
	return 0;
} 
