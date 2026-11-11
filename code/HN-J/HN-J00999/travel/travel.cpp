#include<bits/stdc++.h>
using namespace std;
string cc1,ss1,cc2,ss2;
int minx,maxa;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	cin>>cc1>>ss1>>cc2>>ss2;
	if(cc1[0]==cc2[0]&&cc1[1]==cc2[1]) {
		cout<<1;
	}else{
	cout<<"0000";
	return 0;
	} 
	
	if(ss1[0]==ss2[0]&&ss1[1]==ss2[1]){
		cout<<1;
	} 
	else{
	cout<<"000";
	return 0; 
	}
	minx=min(int(ss1[2]),int(ss2[2]));
	maxa=max(int(ss1[2]),int(ss2[2]));
	if((minx+2==maxa&&minx!=67)||(minx+1==maxa&&minx!=67)){
		cout<<1;
	}else{
		cout<<"00";
		return 0; 
	}
	if(minx+1==maxa){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
