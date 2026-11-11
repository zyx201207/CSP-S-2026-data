#include<bits/stdc++.h>
using namespace std;

string a,b,r,x;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>a>>r>>b>>x;
	
	
	if(a!=b){
		cout<<0<<0<<0<<0;
		return 0;
	}
	cout<<1;
	
	
	
	a=r[0]+r[1];
	b=x[0]+x[1];
	if(a!=b){
		cout<<0<<0<<0;
		return 0;
	}
	cout<<1;
	
	
	char m=r[2];
	char n=x[2];
	if((m>=65&&m<=67&&n>=65&&n<=67)||(m>=68&&m<=69&&n>=68&&n<=69)){
		cout<<1;
		
		int i=m,j=n;
		if(i-j==1||i-j==-1){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	
	cout<<0<<0;
	
	
	return 0;
}
