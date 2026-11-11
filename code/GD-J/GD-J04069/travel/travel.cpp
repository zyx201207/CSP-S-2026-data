#include<bits/stdc++.h>
using namespace std;
string x;
string y;
string xx;
string yy;
bool check(char o,char oo){
	if(o=='A'||o=='B'||o=='C'){
		if(oo=='A'||oo=='B'||oo=='C'){
			return true;
		}
	}
	if(o=='D'||o=='F'){
		if(oo=='D'||oo=='F'){
			return true;
		}
	}
	return false;
}
int main(){
	bool tf=false;
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>x>>y>>xx>>yy;
    int x_s=x.size();
    int y_s=y.size();
    for(int i=0;i<x_s;i++){
    	if(x[i]!=xx[i]){
    	//cout<<x[i]<<" "<<xx[i]<<endl;
    		cout<<"0000";
    		return 0;
		}
	}
	cout<<"1";
	for(int i=0;i<y_s-1;i++){
		if(y[i]!=yy[i]){
			cout<<"000";
			return 0;
		}
	}
	cout<<"1";
	char s=y[y_s-1];
	char ss=yy[y_s-1];
	//cout<<s<<" "<<ss<<endl; 
	if(check(s,ss)){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	if(int(ss)==int(s)+1){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
    return 0;
}
