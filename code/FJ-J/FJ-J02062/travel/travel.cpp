#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
string a1,b1,a2,b2;cin>>a1>>a2>>b1>>b2;
if(a1==b1){//在同车厢 
	cout<<1;
	if(a2[0]==b2[0]&&a2[1]==b2[1])//在同排
	{
		cout<<1;
		double a=a2[2]-'A',b=b2[2]-'A';
		if(a==5)
		a-=1;
		if(b==5)
		b-=1; 
		if((a-2.5)*(b-2.5)>0){//同侧 
		cout<<1;
		if(abs(a-b)==1)
		cout<<1;
		else cout<<0;	
	}
		else cout<<"00";
	 } 
	 else cout<<"000";
}
else cout<<"0000";
	return 0;
} 
