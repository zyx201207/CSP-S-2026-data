#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c){
		cout<<1;
	}
	else{
		cout<<"0000"<<endl;
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
		if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
			cout<<1;
		}
		else{
			cout<<"00"<<endl;
			return 0;
		}
	}
	else{
		if(b[2]=='D'||b[2]=='F'){
			cout<<1;
		}
		else{
			cout<<"00"<<endl;
			return 0;
		}	
	}
    int tmp1=b[2],tmp2=d[2];
    if(abs(tmp1-tmp2)==1){
		cout<<1<<endl;
	}
	else{
		cout<<0<<endl;
	}
    return 0;
}
