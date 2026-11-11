#include <bits/stdc++.h>
using namespace std;
#define ll long long
string a,c;
char b,d,e,f,g,h;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
    cin>>a>>b>>d>>e>>c>>f>>g>>h;
    if(a==c)cout<<1;
    else{cout<<0<<0<<0<<0; return 0;}
    if(b==f&&d==g){
       cout<<1;
    }else{
       cout<<0<<0<<0;
       return 0;
    }
    if(e=='A'||e=='B'||e=='C'){
       if(h=='A'||h=='B'||h=='C'){
          cout<<1;
       }else{cout<<0<<0; return 0;}
    }else{
       if(h=='F'||h=='D')cout<<1;
       else{cout<<0<<0; return 0;}
    }
    if(e-'0'+1==h-'0'||e-'0'==h-'0'+1){
       if(e=='C'&&h=='D')cout<<0;
       else if(h=='C'&&e=='D')cout<<0;
       else cout<<1;
    }
    return 0;
}
