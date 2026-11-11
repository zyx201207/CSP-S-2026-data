#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,a2,b1,b2,c1,c2;
	char a,b,c,d,e,f,g,h,i,j;
	cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j;
	a1=a*10+b;
	a2=f*10+g;
	b1=c*10+d;
	b2=h*10+i;
	c1=e-'A'+1;
	c2=j-'A'+1;
	if(a1!=a2){
		cout<<"0000";
		return 0;
	}
	if(b1!=b2){
		cout<<"1000";
		return 0; 
	}
	if((c1<=3&&c2>3)||(c1>3&&c2<=3)){
		cout<<"1100";
		return 0;
	}
	if(c1-c2!=1&&c1-c2!=-1){
		cout<<"1110";
		return 0; 
	}
	cout<<"1111"; 
	return 0;
} 
