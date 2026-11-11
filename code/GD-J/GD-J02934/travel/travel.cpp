#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a1,b1;
	string a2,b2;
	cin>>a1>>a2>>b1>>b2;
	int tmp=0;
	if(a1==b1){
		cout<<1;
		tmp=1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	string c1=a2.substr(0,2),c2=b2.substr(0,2);
	int sum=0;
	if(c1==c2 && tmp==1){
		cout<<1;
		sum=1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	string d1=a2.substr(2,1),d2=b2.substr(2,1);
	if(d1<="C" && d2<="C" && sum==1 && tmp==1){
		cout<<1;
	}
	else if(d1>="D" && d2>="D"&&sum==1 && tmp==1){
		cout<<1;
	}else{
		cout<<0<<0;
		return 0;
	}
	char d3=a2[2],d4=b2[2];
	int dd=d3-d4;
	if(dd<0){
		dd=-dd;
	}
	if(dd==1 && sum==1 && tmp==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
