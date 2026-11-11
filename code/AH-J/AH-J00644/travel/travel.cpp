#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a1,b1,x,y,al,bl;
string a2,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	al=a2.size(),bl=b2.size();
	if(a1==b1){
		cout<<1;
		for(ll i=1;i<al;i++){
			if(a2[i]>='0'&&a2[i]<='9') x=x*10+a2[i]-'0';
		}for(ll i=1;i<bl;i++){
			if(b2[i]>='0'&&b2[i]<='9') y=y*10+b2[i]-'0';
		}if(x==y){
			cout<<1;
			if((a2[al-1]<='C'&&b2[bl-1]<='C')||(a2[al-1]>'C'&&b2[bl-1]>'C'&&a2[al-1]<='F'&&b2[bl-1]<='F')){cout<<1;
				if((a2[al-1]=='A'&&b2[bl-1]=='B')||(a2[al-1]=='B'&&b2[bl-1]=='A')||(a2[al-1]=='C'&&b2[bl-1]=='B')||(a2[al-1]=='B'&&b2[bl-1]=='C')||(a2[al-1]=='E'&&b2[bl-1]=='F')||(a2[al-1]=='E'&&b2[bl-1]=='F')) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
