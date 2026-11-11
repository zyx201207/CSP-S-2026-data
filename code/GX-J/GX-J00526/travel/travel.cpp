#include <bits/stdc++.h>
using namespace std;
string s,m;
int a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> a >> b >> s >>c >> d >> m;
    if(a==c){
        cout <<"1";
    }
    else{
        cout <<"0";
    }
    if(b==d){
        cout <<"1";
    }
    else{
        cout <<"0";
    }
    if(a!=c){
		cout << "0";
	}
	else{
		cout << "1";
	}
    if(a!=c&&b!=d){
        cout <<"0";
    }
    else{
        cout <<"1";
    }
    return 0;
}
