#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	char seat1=s1[2];
	char seat2=s2[2];
	bool a1=seat1>='D'?1:0;
	bool a2=seat2>='D'?1:0; 
	bool is1=0,is2=0,is3=0,is4=0;
	if(c1==c2){
		is1=1;
		if(s1.substr(0,2)==s2.substr(0,2)){
			is2=1;
			if(a1==a2){
				is3=1;
				if(is3&&(seat1-seat2==1||seat1-seat2==-1))is4=1;
			}
		}
	}
	cout<<is1<<is2<<is3<<is4;
	return 0;
} 
