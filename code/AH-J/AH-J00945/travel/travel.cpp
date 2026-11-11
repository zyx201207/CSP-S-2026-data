#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string x1,x2,y1,y2;
	cin>>x1>>x2>>y1>>y2;
	ll f1=0;
	ll f2=0;
	ll f3=0;
	ll f4=0;
	if(x1==y1)f1=1;
	else{
		cout<<"0000";
		return 0;
	}
	if(x2[0]==y2[0]&&x2[1]==y2[1]){
		f2=1;
		if((x2[2]<='C'&&y2[2]<='C')||(x2[2]>='D'&&y2[2]>='D'))f3=1;
		else f3=0;
	}else{
		f2=0,f3=0;
	}
	if(abs(x2[2]-y2[2])>=2||(x2[2]=='D'&&y2[2]=='C')||(x2[2]=='C'&&y2[2]=='D'))f4=0;
	else if(x2[0]!=y2[0]||x2[1]!=y2[1])f4=0;
	else f4=1;
	cout<<f1<<f2<<f3<<f4;
	
	return 0;
}
