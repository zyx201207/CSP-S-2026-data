#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool gf[205][205],gf2[205][205];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	gf['A']['B']=1;
	gf['A']['C']=1;
	gf['B']['C']=1;
	gf['D']['F']=1;
	gf['B']['A']=1;
	gf['C']['A']=1;
	gf['C']['B']=1;
	gf['F']['D']=1;
	gf2['A']['B']=1;
	gf2['B']['C']=1;
	gf2['D']['F']=1;
	gf2['B']['A']=1;
	gf2['C']['B']=1;
	gf2['F']['D']=1;
	if(a!=c){
		cout<<"0000";
	}else if(b[0]==d[0]&&b[1]==d[1]){
		cout<<"11"<<gf[b[2]][d[2]]<<gf2[b[2]][d[2]];
	}else{
		cout<<"1000";
	}
	return 0;
}
