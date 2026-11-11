#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	string b1[10],b2,d1[10],d2;
	b1[0]=b[0];
	b1[1]=b[1];
	b2=b[2];
	d1[0]=d[0];
	d1[1]=d[1];
	d2=d[2];
	//cout<<b1[1]<<d1[1];
	if(b1[1]==d1[1]&&b1[0]==d1[0]){
		
		cout<<1;
	}
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if(b2[0]>='D'&&d2[0]>='D'||b2[0]<'D'&&d2[0]<'D'){
		cout<<1;
	}
	else{
		cout<<0<<0;
		return 0;
	}
	if(b2[0]-d2[0]==1||d2[0]-b2[0]==1){
		cout<<1;
	}
	else{
		cout<<0;
		return 0;
	}
	
	return 0;
}
