#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d;
	char e,f;
	cin>>a>>b>>e>>c>>d>>f;
	if(a==c) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(b==d) cout<<1;
	else{
		cout<<"000";
		return 0; 
	}
	if((int)e-64>=1&&(int)e-64<=3&&(int)f-64<=3&&(int)f-64>=1||((int)e-64==4&&(int)f-64==6)||((int)e-64==6&&(int)f-64==4)) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if((int)e-1==(int)f||(int)e+1==(int)f) cout<<1;
	else cout<<0;
	return 0;
} 
