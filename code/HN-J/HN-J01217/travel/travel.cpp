#include<bits/stdc++.h>
using namespace std;
int a,b;
string x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>x>>b>>y;
	if(a==b){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(x[0]==y[0]){
		if(x[1]==y[1]){
			cout<<1;
		}else{
			cout<<"000";
			return 0;
		}
		
	}else{
		cout<<"000";
	}
	if(x[2]=='D'){
		if(y[2]=='F'){
			cout<<"11";
			return 0;
		}else{
			cout<<"00";
			return 0;
		}
	}else if(x[2]=='A'||x[2]=='B'||x[2]=='C'){
		if(y[2]=='D'||y[2]=='F'){
			cout<<"00";
			return 0;
		}else{
			if(int(x[2])==int(y[2])+1||int(x[2])==int(y[2])-1){
				cout<<"11";
				return 0;
			}else{
				cout<<"10";
				return 0;
			}
		}
	}
	return 0;
} 
