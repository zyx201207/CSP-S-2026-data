#include<bits/stdc++.h>
using namespace std;
typedef long long lo;
lo i,j,k,l,n,m,mm,r,s,ss;
string h,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>l>>h>>r>>d;
	if(l!=r){
		cout<<"0000";
		return 0;
	}
	l=(h[0]-'0')*10+(h[1]-'0'),r=(d[0]-'0')*10+(d[1]-'0');
	if(l!=r){
		cout<<"1000";
		return 0;
	}
	if(d[2]<='C'&&h[2]<='C'){
		if(d[2]=='A'&&h[2]=='C'||d[2]=='C'&&h[2]=='A'){
			cout<<"1110";
		}
		else cout<<"1111"; 
	}
	if(d[2]>='D'&&h[2]>='D')cout<<"1111";
	if((d[2]<='C'&&h[2]>='D')||(d[2]>='D'&&h[2]<='C'))cout<<"1100";
	return 0;
}
