#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    int a,b;
    string as,bs;
    cin>>a>>as>>b>>bs;
    int A=(as[0]-'0')*10+(as[1]-'0');
    int B=(bs[0]-'0')*10+(bs[1]-'0');
    char aa=as[2];
    char bb=bs[2];
    if(a!=b){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	bool f=false;
	if(A==B){
	    cout<<"1";
	    if((aa=='A'||aa=='B'||aa=='C')&&(bb=='A'||bb=='B'||bb=='C')){
	        cout<<'1';
	        if((aa=='A'&&bb=='C')||(aa=='C'&&bb=='A')){
		    }
	        else
	            f=true;
	    }
	    else if((aa=='D'||aa=='E')&&(bb=='D'||bb=='E')){
	        cout<<"1";
	        f=true;
		}
	    else
	        cout<<"0";
	}
	else
	    cout<<"00";
	if(f==true) cout<<"1";
	else cout<<"0";
    return 0;
}
