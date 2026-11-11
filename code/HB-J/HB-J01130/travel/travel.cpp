#include<bits/stdc++.h>
using namespace std;
int x[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b; string c,d;
	cin>>a>>c>>b>>d;
		if(a==b){
		x[0]=1;
		if(c[0]==d[0]&&c[1]==d[1]){
		x[1]=1;
		if((c[2]=='C'&&d[2]=='D'||c[2]=='D'&&d[2]=='C')!=1){
		x[2]=1;
		if(c[2]+1==d[2]||c[2]-1==d[2]){
		if(c[2]!='E'&&d[2]!='E'){
		x[3]=1;
		}
		}
		else x[3]=0;
		}
		else x[2]=0;
		}
		else x[1]=0;
		}
		else x[1]=0;
	for(int i=0;i<4;i++){
		cout<<x[i]<<" ";
		}
	return 0;
	}
