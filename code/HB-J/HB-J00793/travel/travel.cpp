#include<bits/stdc++.h>
using namespace std;
string s1,s2,ss1,ss2;
int f;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>ss1>>ss2;
    if(s1==ss1) cout<<1;
    else cout<<0;
    if(s2[0]==ss2[0]&&s2[1]==ss2[1]&&s1==ss1) cout<<1;
    else cout<<0;
    if(s2[2]<='C'&&ss2[2]<='C'&&s2[0]==ss2[0]&&s2[1]==ss2[1]&&s1==ss1){
		cout<<1;
		f=1;
	}
    else if(s2[2]>'C'&&ss2[2]>'C'&&s2[0]==ss2[0]&&s2[1]==ss2[1]&&s1==ss1){
		cout<<1;
		f=1;
	}
    else cout<<0;
    if(f==1&&abs(s2[2]-ss2[2])==1) cout<<1;
    else cout<<0;
    return 0;
}
