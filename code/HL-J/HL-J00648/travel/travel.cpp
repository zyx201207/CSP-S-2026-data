#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string a[1001];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=4;i++){
		cin>>a[i];
	}
	
	
	if(a[1]==a[3]){
		cout<<1;	
	}else {
		cout<<"0000";
		return 0; 
	}
	
	
    string x,y;
    ll cnt=0;
    x=a[2];
    y=a[4];
    for(int i=0;i<=1;i++){
    	if(x[i]==y[i]){
		cnt++;
		}
	}
	if(cnt==2){
		cout<<"1";
	}else {
		cout<<"000";
		return 0;
	}
	 
	 
	if(x[2]>='A'&&x[2]<='C'&&y[2]>='A'&&y[2]<='C'||x[2]>='D'&&x[2]<='F'&&y[2]>='D'&&y[2]<='F'){
		cout<<"1";
	} else {
		cout<<"00";
		return 0;
	}
	
	
	if(x[2]=='A'&&y[2]=='B'||x[2]=='B'&&y[2]=='C'&&x[2]=='D'&&y[2]=='E'||x[2]=='E'&&y[2]=='F'){
		cout<<"1";
	} else cout<<"0";
	return 0; 
} 
