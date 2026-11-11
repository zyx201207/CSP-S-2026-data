#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string x,y,x_1,y_1;
	bool f=false,n=false;
	cin>>x>>y>>x_1>>y_1;
	if(x==x_1)cout<<1,n=true;//1
	else cout<<0;
	if(n==false){
		cout<<"000";
		return 0;
	}
	if(y[0]==y_1[0]&&y[1]==y_1[1])cout<<1,f=true;//2
	else cout<<0;
	if(f==false)cout<<0;//3
	else if((y[2]>='A'&&y[2]<='C'&&y_1[2]>='A'&&y_1[2]<='C')||(y[2]>='D'&&y[2]<='F'&&y_1[2]>='D'&&y_1[2]<='F')&&f==true)cout<<1;
	else cout<<0;
	if((y[2]=='C'&&y_1[2]=='D')||(y[2]=='D'&&y_1[2]=='C'))cout<<0;//4
	else if(y[0]==y_1[0]&&y[1]==y_1[1]&&((y[2]+1==y_1[2])||(y[2]-1==y_1[2])))cout<<1;
	else cout<<0;
	return 0;
}
