#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
long long ans[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		ans[0]=1;
	}
	else{
		ans[0]=0; ans[1]=0; ans[2]=0; ans[3]=0;
		exit(0);
	}
	if(b[0]==d[0]&&b[1]==d[1]){
		ans[1]=1;
	}
	else{
		ans[1]=0; ans[2]=0; ans[3]=0;
		exit(0);
	}
	
	if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
		if(d[2]=='A'||d[2]=='B'||d[2]=='C')
			ans[2]=1;
		else
			ans[2]=0;
	}
	if(b[2]=='D'||b[2]=='F'){
		if(d[2]=='D'||d[2]=='F')
			ans[2]=1;
		else
			ans[2]=0;
	}
	if((b[2]!='D'&&b[2]!='F')&&(d[2]!='D'&&d[2]!='F')){
		if(b[2]+1==d[2]||b[2]-1==d[2])
			ans[3]=1;
		else
			ans[3]=0;
	}
	else if((b[2]=='D'&&d[2]=='F')||(d[2]=='D'&&b[2]=='F'))
		ans[3]=1;
	else
		ans[3]=0;
	for(int i=0;i<=3;i++)
		cout<<ans[i];
	return 0;
}
