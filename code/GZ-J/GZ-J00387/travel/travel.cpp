//GZ-00387 贵阳市南明区华麟学校 杨博麟 
#include<bits/stdc++.h>
using namespace std;
string x,y,m,n;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>m>>x>>n>>y;
	if(m==n) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	if(x[0]==y[0] && x[1]==y[1]) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if((('A'<=x[2] && x[2]<='C')&&('A'<=y[2] && y[2]<='C'))||((x[2]=='D' || x[2]=='F')&&(y[2]=='D' || y[2]=='F'))) cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	if(x>y) swap(x,y);
	if(y[2]==x[2]+1 || (x[2]=='D' && y[2]=='F')) cout<<"1";
	else cout<<"0";
	return 0;
}
