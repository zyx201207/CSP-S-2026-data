#include <bits/stdc++.h>

using namespace std;

string c1;
string s1;
string c2;
string s2;
string n = "1";
string m = "0";

int a[1005];


int main() {
	//freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
cin >>c1>> s1 >>  c2 >> s2 ;

    if( c1 == c2 ){
        if(s1 == s2){
            cout << n << m <<m<< m;

        }
    else{
        cout << m << n << n << n;
    }
    }






return 0;
}
