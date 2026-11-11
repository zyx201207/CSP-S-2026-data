#include<bits/stdc++.h>
using namespace std;
string a,b,a1,b1; 
bool flag=false;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b>>a1>>b1;
	
	if(a==a1)cout<<1;
	else cout<<0;
	
	if(a==a1&&b[0]==b1[0]&&b[1]==b1[1])cout<<1;
	else cout<<0;
	
	if(a==a1&&b[0]==b1[0]&&b[1]==b1[1]){
		if( (b[2]=='A'||b[2]=='B'||b[2]=='C') && (b1[2]=='A'||b1[2]=='B'||b1[2]=='C') ){
			cout<<1;
		}else if( (b[2]=='D'||b[2]=='F') && (b1[2]=='D'||b1[2]=='F') ){
			cout<<1;
		}else{
			cout<<0;
			flag=true;
		}
	}else cout<<0;
	
	if(a==a1&&b[0]==b1[0]&&b[1]==b1[1]&&(b[2]-1==b1[2]||b1[2]-1==b[2])&&!flag)cout<<1;
	else cout<<0;
	return 0;
}
