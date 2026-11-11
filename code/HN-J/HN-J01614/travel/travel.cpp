#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int tran_a,tran_b;
int list_a,list_b;
int line_a,line_b;

string tick_a,tick_b;

int main(){
	
	freopen("trave.in","r",stdin);
	freopen("trave.out","w",stdout);
	
	cin>>tran_a>>tick_a;
	cin>>tran_b>>tick_b;
	
	list_a=(tick_a[0]-'0')*10+(tick_a[1]-'0');
	list_b=(tick_b[0]-'0')*10+(tick_b[1]-'0');
	
	line_a=(tick_a[2]-'A');
	line_b=(tick_b[2]-'A');
	
	if(line_a==5) line_a--;
	if(line_b==5) line_b--;
	
	//cout<<tran_a<<" "<<list_a<<" "<<line_a<<endl;
	//cout<<tran_b<<" "<<list_b<<" "<<line_b<<endl;
	
	if(tran_a == tran_b)
		cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	
	if(list_a == list_b)
		cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	
	if((line_a<=2 && line_b<=2) || (line_a>=3 && line_b>=3))
		cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	
	if((line_a==2 && line_b==3) || (line_a==3 && line_b==2)){
		cout<<"0";
		return 0;
	}
	
	if(abs(line_a-line_b)==1)
		cout<<"1";
	else
		cout<<"0";
		
	return 0;
}
//Trick||Treat!
