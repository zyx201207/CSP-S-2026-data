#include<bits/stdc++.h>
using namespace std;
int c1[100],s1[100],c2[100],s2[100];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>c1[1]>>s1[1]>>c2[1]>>s2[1];
    if(c1[1]==c2[1]){
    	cout<<1;
	}
	else{
		cout<<0;
	}
	if(c1[1]/10==c2[1]/10){
		cout<<1;
	}
	else{
		cout<<0;
	}
    cout<<1||0;
    cout<<1||0;
	return 0;
}
