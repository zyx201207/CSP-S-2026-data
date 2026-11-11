#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	int x1,x2,num=0;
	cin>>a>>b>>c>>d;
	x1=(a[0]-'0')*10+a[1]-'0';
	x2=(c[0]-'0')*10+c[1]-'0';
	if(x1>17||x1<=1||x1==16||x2>17||x2<=1||x2==16){
		cout<<"0000"<<endl;
		return 0;
	}
	if(x1==x2) num=num*10+1;
	else{
		cout<<"0000"<<endl;
		return 0;
	}
	
	x1=(b[0]-'0')*10+b[1]-'0';
	x2=(d[0]-'0')*10+d[1]-'0';
	if(x1>18||x2>18||b[2]<'A'||b[2]>'F'||b[2]=='E'||d[2]<'A'||d[2]>'F'||b[2]=='E'){
		cout<<"0000"<<endl;
		return 0;
	}
	if(x1==x2) num=num*10+1;
	else{
		cout<<"1000"<<endl;
		return 0;
	}
	
	if((b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')||((b[2]=='D'||b[2]=='F'&&d[2]=='D'||d[2]=='F')&&b[2]-d[2]!=0)) num=num*10+1;
	if(b[2]-d[2]==0){
		cout<<"1100"<<endl;
		return 0;
	}
	
	if((b[2]=='F'||d[2]=='F'&&abs(b[2]-d[2])==2)||b[2]<'D'&&d[2]<'D'&&abs(d[2]-b[2])==1) num=num*10+1;
	else{
		cout<<"1110"<<endl;
		return 0;
	}
	cout<<num<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
