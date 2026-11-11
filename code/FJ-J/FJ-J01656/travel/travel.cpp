#include<bits/stdc++.h>
using namespace std;
int c2,c1;
string s1,s2;
int a1[37],a2[37];
bool check1(){
	if(s1[2]<='C'&&s2[2]<='C') return 1;
	if(s1[2]>='D'&&s2[2]>='D') return 1;
    return 0;
    }
bool check2(){
    if(abs(s1[2]-s2[2])==1 )return 1;
    return 0;
    }
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);	
	cin>>c1>>s1>>c2>>s2;
	a1[1]=s1[0]-'0';
	a1[2]=s1[1]-'0';
	a2[1]=s2[0]-'0';
	a2[2]=s2[1]-'0';
	if(c1==c2) cout<<1;
	else{
	    cout<<0<<0<<0<<0;
	    return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]) {
		cout<<1;
	}
	else{
		cout<<0<<0<<0;
		return 0;
		}
	if(check1()) cout<<1;
	else{
	    cout<<0<<0;
	    return 0;
	}
	if(check2()) cout<<1;
	else{
	    cout<<0;
	    return 0;
	}
	return 0;
}
