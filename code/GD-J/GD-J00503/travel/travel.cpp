#include<bits/stdc++.h>
#define int long long
using namespace std;
string a,b,c,d;
bool flag[5];
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c) flag[0]=1;
	if(flag[0]==1&&b[0]==d[0]&&b[1]==d[1]) flag[1]=1;
	if(flag[1]==1){
		if(b[2]=='D'&&d[2]=='F') flag[2]=1;
		if(b[2]=='F'&&d[2]=='D') flag[2]=1;
		if(b[2]=='C'&&d[2]=='B') flag[2]=1;
		if(b[2]=='C'&&d[2]=='A') flag[2]=1;
		if(b[2]=='B'&&d[2]=='A') flag[2]=1;
		if(b[2]=='B'&&d[2]=='C') flag[2]=1;
		if(b[2]=='A'&&d[2]=='B') flag[2]=1;
		if(b[2]=='A'&&d[2]=='C') flag[2]=1;
	}
	if(flag[2]==1){
		if(b[2]=='D'&&d[2]=='F') flag[3]=1;
		if(b[2]=='F'&&d[2]=='D') flag[3]=1;
		if(b[2]=='C'&&d[2]=='B') flag[3]=1;
		if(b[2]=='B'&&d[2]=='A') flag[3]=1;
		if(b[2]=='B'&&d[2]=='C') flag[3]=1;
		if(b[2]=='A'&&d[2]=='B') flag[3]=1;
	}
	for(int i=0;i<=3;i++) cout<<flag[i];
	return 0;
} 
