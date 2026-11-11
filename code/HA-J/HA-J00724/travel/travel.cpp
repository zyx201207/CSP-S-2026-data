#include<bits/stdc++.h>
using namespace std;
string a,b;
int c,d,x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>a>>d>>b;
	if(a[2]=='A'||a[2]=='B'||a[2]=='C')x=1;
	if(b[2]=='A'||b[2]=='B'||b[2]=='C')y=1;
	if(c!=d){
		cout<<"0000";
		return 0;
	}else if(a[0]!=b[0]||a[1]!=b[1]){
		cout<<"1000";
		return 0;
	}else if(x!=y){
		cout<<"1100";
		return 0;
	}else if(abs(a[2]-b[2])==2&&(!(a[2]=='D'||a[2]=='F')))cout<<"1110";
	else cout<<"1111";
	return 0;
}
