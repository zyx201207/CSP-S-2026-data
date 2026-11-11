#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,s1,c2,s2;
ll a,b,c,d,x,y,p,q;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(ll i=0;i<c1.size();i++){
		a+=ll(c1[i]-'0');
		if(i==0)a*=10;
	}
	for(ll i=0;i<c2.size();i++){
		b+=ll(c2[i]-'0');
		if(i==0)b*=10;
	}
	for(ll i=0;i<s1.size();i++){
		if(i!=2){
			c+=ll(s1[i]-'0');
			if(i==0)c*=10;
		}
		else{
			p=ll(s1[i]-'A'+1);
			if(s1[i]=='A'||s1[i]=='B'||s1[i]=='C'){
				x=1;
			}
			else  x=0;
		}
	}
		for(ll i=0;i<s2.size();i++){
		if(i!=2){
			d+=ll(s2[i]-'0');
			if(i==0)d*=10;
		}
		else{
			q=ll(s2[i]-'A'+1);
			if(s2[i]=='A'||s2[i]=='B'||s2[i]=='C'){
				y=1;
			}
			else  y=0;
		}
	}
	if(a==b)cout<<1;
	else    cout<<0;
	if(a==b&&c==d)cout<<1;
	else          cout<<0;
	if(a==b&&c==d&&x==y)cout<<1;
	else                cout<<0;
	if((a==b&&c==d&&x==y&&abs(p-q)==1)||(a==b&&abs(c-d)==1&&p==q&&x==y))cout<<1;
	else                                                    cout<<0;
	return 0;
}
