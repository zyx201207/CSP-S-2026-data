#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,l,r,ans[114];
string x,y;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>x>>m>>y;
	l=x[0]*10+x[1]-'0'*11,r=y[0]*10+y[1]-'0'*11;
	if(n==m){
		ans[1]=1;
		if(l==r){
			ans[2]=1;
			if((x[2]=='A'&&(y[2]=='B'||y[2]=='C'))||(x[2]=='D'&&y[2]=='F')||
			(x[2]=='B'&&(y[2]=='A'||y[2]=='C'))||(x[2]=='F'&&y[2]=='D')||
			(x[2]=='C'&&(y[2]=='A'||y[2]=='B'))){
				ans[3]=1;
				if((x[2]=='A'&&y[2]=='B')||(x[2]=='B'&&y[2]=='C')||(x[2]=='D'&&y[2]=='F')||
				(x[2]=='B'&&y[2]=='A')||(x[2]=='C'&&y[2]=='B')||(x[2]=='F'&&y[2]=='D')) ans[4]=1;
			}
		}
	}
	for(int i=1;i<=4;i++) cout<<ans[i];
}
