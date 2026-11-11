#include<bits/stdc++.h>
using namespace std;
int n,m;
string x,y;
map<int,bool> mp[17];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>x>>m>>y;
	mp[0][1]=true;
	mp[1][2]=true;
	mp[1][0]=true;
	mp[2][1]=true;
	mp[3][4]=true;
	mp[4][3]=true;
	if(n==m) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	if(x[0]==y[0] && x[1]==y[1]) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if((x[2]<='C' && y[2]<='C') || (x[2]>='D' && y[2]>='D')) cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	if(mp[(int)x[2]-'A'][(int)y[2]-'A']) cout<<"1";
	else cout<<"0";
	return 0;
}
