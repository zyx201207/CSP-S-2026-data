#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
char e,f;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>e>>c>>d>>f;
    if(a!=c){
        cout<<"0000";
        return 0;
    }
    if(b!=d){
    	cout<<"1000";
    	return 0;
	}
	if((e>'C'&&f<'D')||(e<'D'&&f>'C')){
		cout<<"1100";
		return 0;
	}
	if((e-f==1)||(f-e==1)){
		cout<<"1111";
		return 0;
	}
	cout<<"1110";
    return 0;
}

