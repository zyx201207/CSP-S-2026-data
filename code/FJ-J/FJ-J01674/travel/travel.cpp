#include<bits/stdc++.h>
using namespace std;
string a,b,c,d; int ans[5];
int main(){
	freopen("travel.in","r",stdin); 
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c) ans[1]=1; 
	else ans[1]=0;
	if(ans[1]==1&&b[0]==d[0]&&b[1]==d[1]) ans[2]=1;
	else ans[2]=0;
	if(ans[2]==1){
		if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C')) ans[3]=1;
		else if((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F')) ans[3]=1;
		else ans[3]=0;
	}else ans[3]=0;
	if(ans[3]==1){
		if((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='A')) ans[4]=1;
		else if((b[2]=='B'&&d[2]=='C')||(b[2]=='C'&&d[2]=='B')) ans[4]=1;
		else if((b[2]=='C'&&d[2]=='D')||(b[2]=='D'&&d[2]=='C')) ans[4]=0;
		else if((b[2]=='D'&&d[2]=='E')||(b[2]=='B'&&d[2]=='A')) ans[4]=1;
		else ans[4]=0;}
	else ans[4]=0;
	for(int i=1;i<=4;i++) cout<<ans[i];
	return 0;
} 
