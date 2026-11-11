#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    string a1,a2,b1,b2;
    int t = 0;
    cin>>a1>>a2>>b1>>b2;
    if(a1==b1){
    	cout<<1;
    	t = 1;
    }
    else{
    	cout<<0;
    	t = 0;
    }
    if(t==1&&a2[0]==b2[0]&&a2[1]==b2[1]){
    	cout<<1;
    	t = 1;
    }
    else{
    	cout<<0;
    	t = 0;
    }
    if(t==1&&((a2[2]>'C'&&b2[2]>'C')||(a2[2]<='C'&&b2[2]<='C'))){
    	cout<<1;
    	t = 1;
    }
    else{
    	cout<<0;
    	t = 0;
    }
    if(t==1&&abs(a2[2]-b2[2])==1&&!(a2[2]=='C'&&b2[2]=='D')&&!(a2[2]=='D'&&b2[2]=='C')){
    	cout<<1;
    }
    else{
    	cout<<0;
    }
	return 0;
}
