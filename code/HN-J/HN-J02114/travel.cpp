#include<bits/stdc++.h>
using namespace std;
int a,b;
string x,y;                           
int main(){
    cin>>a;
    cin>>x;
    cin>>b;
	cin>>y;
	int cx;
	if(a==b){
		cx=1;
		cout<<cx;
	}else{
		cx=0;
		cout<<cx;
	}
	string bs1,bs2;
	for(int i=0;i<x.size();i++){
		if(x[i]>='0'&&x[i]<='9'){
			bs1+=x[i];
		}
	}
	for(int i=0;i<y.size();i++){
		if(y[i]>='0'&&y[i]<='9'){
			bs2+=y[i];
		}
	}
	int bs;
	if(bs1==bs2&&cx==1){
		bs=1;
		cout<<bs;
	}else{
		bs=0;
		cout<<bs;
	}
	int tc;
	if(((x[x.size()-1]<='C'&&y[y.size()-1]<='C')||(x[x.size()-1]>'C'&&y[y.size()-1]>'C'))&&cx==1&&bs==1){
	    tc=1;
	    cout<<tc;
	}else{
		tc=0;
		cout<<tc;
	}
	if((x[x.size()-1]==y[y.size()-1]+1||x[x.size()-1]==y[y.size()-1]-1)&&tc==1){
		cout<<1; 
	}else{
		cout<<0;
	}
	return 0;
}
