#include <bits/stdc++.h>
using namespace std;
int w[99999999];
int t[99999999][0];
int main()
{
	freopen("wubway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>t[i][0];
	}
	int xr,yr;
	cin>>xr>>yr;
	
	int distance =w[0]+t[0][0]+t[0][1]+w[1];
	
	int foot = w[0]+t[0][0]+t[1][0]+w[2];
	cout<<foot<<"\n"<<distance;
	return 0;	
} 
