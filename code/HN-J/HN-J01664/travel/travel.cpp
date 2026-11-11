#include<bits/stdc++.h>
using namespace std;
int a,b,p1,p2;
string x,y;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>x>>b>>y;
	if(a!=b){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	p1=(x[0]-'0')*10+(x[1]-'0');
	p2=(y[0]-'0')*10+(y[1]-'0');
	if(p1!=p2){
		cout<<"000";
		return 0;
	}
	cout<<1;
	p1=x[2]-'A'+1;
	p2=y[2]-'A'+1;
	if((p1<4&&p2>3)||(p1>3&&p2<4)){
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(abs(p2-p1)==1) cout<<1;
	else cout<<0;
	return 0;
}//Accepted
//我也要旅游 
