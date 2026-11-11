#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,x,y;
	cin>>a>>x>>b>>y;
	if(a==b)  cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(x[0]==y[0]&&x[1]==y[1])  cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(x[2]-'A'<3&&y[2]-'A'<3||x[2]-'A'>=3&&y[2]-'A'>=3)  cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(abs(x[2]-y[2])==1)  cout<<1;
	else{
		cout<<"0";
		return 0;
	}
	return 0;
}

