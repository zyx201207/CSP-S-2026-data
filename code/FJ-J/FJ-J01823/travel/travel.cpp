#include<bits/stdc++.h>
using namespace std;
string a,b,x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>x>>y;
	if(a==x)cout<<1;
	else{
		cout<<0<<0<<0<<0;
		return 0;
	} 
	if(b[0]==y[0]&&b[1]==y[1]){
		cout<<1;	
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
		if(y[2]=='A'||y[2]=='B'||y[2]=='C'){
			cout<<1;
			if(abs(int(y[2])-int(b[2])))cout<<1;
			else cout<<0;
			return 0;
		}else{
			cout<<0<<0;
			return 0;
		}
	}
	if(b[2]=='D'||b[2]=='F'){
		if(y[2]=='D'||y[2]=='F'){
			cout<<1<<1;
			return 0;
		}else{
			cout<<0<<0;
			return 0;
		}
	}
	return 0;
}
