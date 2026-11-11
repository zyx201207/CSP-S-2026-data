#include<bits/stdc++.h>
using namespace std;
struct stu{
	int che,zuo;
	char p;
};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	stu a[3];
	for(int i=1;i<=2;i++){
		cin>>a[i].che>>a[i].zuo>>a[i].p;
	}
	if(a[1].che==a[2].che){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(a[1].zuo==a[2].zuo){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if(a[1].p<='C'&&a[2].p<='C'||a[1].p<'C'&&a[2].p<'C'){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	if(abs(a[1].p-a[2].p)==1){
		cout<<"1";
	}
	else{
		cout<<"0";
		return 0;
	}
	return 0;
} 
