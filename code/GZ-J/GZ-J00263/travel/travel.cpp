/*GZ-J00263 贵阳市第二实验中学 莫卓均*/ 
#include<bits/stdc++.h>
using namespace std;
int a,s,d1,f1;
string d,f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>d>>s>>f;
	if(a==s){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(d[0]==f[0] && d[1]==f[1]){
		cout<<1;
	}
	else{
		cout<<0;
	}
	d1=d[2];
	f1=f[2];
	if(d1>f1){
		swap(d1,f1);
	}
	if(d1==65 && f1==67 || d1==66 && f1==67 || d1==65 && f1==66 || d1==68 && f1==69){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(f1-d1==1 && f1!=68){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
