#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,s1,c2,s2;
bool f,f1,f2;
ll x,y;
char a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	x = (s1[0]-'0')*10 + (s1[1]-'0');
	y = (s2[0]-'0')*10 + (s2[1]-'0');
	if(x == y){
		cout<<1;
		f1 = 1;
	}else{
		cout<<0;
	}
	if(f1 && (s1[2]>=65 && s1[2]<=67 && s2[2]>=65 && s2[2]<=67) || ((s1[2]=='F' && s2[2]=='D') || (s1[2]=='D' && s2[2]=='F'))){
		cout<<1;
		f = 1;
	}else{
		cout<<0;
		f = 0;
	}
	a = s1[2]; b = s2[2];
	if(!f){
		cout<<0;
	}else{
        if(((a+1 == b) || (a-1 == b)) && !((a=='D' && b=='C') || (a=='C' && b=='D'))){
            cout<<1;
        }else if((a=='D' && b=='F') || (a=='F' && b=='D')){
            cout<<1;
        }else{
            cout<<0;
        }
	}
    return 0;
}
