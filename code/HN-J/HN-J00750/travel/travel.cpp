#include<bits/stdc++.h>
using namespace std;
string a,b;
int c,d,x,r,w;
int main(){
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>c>>a>>d>>b;
	x=a[2]-'0'-16;
	r=b[2]-'0'-16;
	if(c==d){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	
	if(a[0]==b[0] && a[1]==b[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	
	if(x==4 || x==5 && r==4 || r==5){
		cout<<"11";
		return 0;
	}
	if(x==1 || x==2 || x==3 && r==1 || r==2 || r==3){
		int z=abs(x-r);
		if(z==1){
			cout<<"11";
			return 0;
		}else{
			cout<<"10";
			return 0;
		}
	}
	cout<<"00";
	return 0;
} 
