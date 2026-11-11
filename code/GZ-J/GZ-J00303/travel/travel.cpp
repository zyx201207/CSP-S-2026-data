//GZ-J00303 遵义四中 郑安迪 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	if(x1!=x2){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<'1';
	}
	string aa,bb;
	aa=y1[0]+y1[1];
	bb=y2[0]+y2[1];
	if(aa!=bb){
		cout<<"000";
		return 0;
	}
	else{
		cout<<'1';
	}
	int a1,b1,c1;
	a1=y1[2];
	b1=y2[2];
	c1='C';
	if(a1>c1 && b1<=c1){
		cout<<"00";
		return 0;
	}
	else if(a1<=c1 && b1>c1){
		cout<<"00";
		return 0;
	}
	else{
		cout<<'1';
	}
	int d1=(a1-b1)*(a1-b1);
	if(d1==1){
		cout<<'1';
	}
	else{
		cout<<'0';
	}
	cout<<" "<<a1<<" "<<b1<<" "<<c1;
	return 0;
}

