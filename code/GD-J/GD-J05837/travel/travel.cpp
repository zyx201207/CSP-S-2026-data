#include<bits/stdc++.h >
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,n,d,s,k="0000";
	int y=0,l=0;
	cin>>c>>n>>s>>d;
	if(c==s){
		k[0]='1';
	}
	if(n[0]==d[0]&&n[1]==d[1]&&k[0]=='1'){
		k[1]='1';
	}
	if(n[2]=='A'||n[2]=='B'||n[2]=='C'){
		y=1;
	}
	if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
		l=1;
	}
	if(l==y&&k[1]=='1'){
		k[2]='1';
	}
	int f=n[2]-d[2];
	if((f==1||f==-1)&&k[2]=='1'){
		k[3]='1';
	}
	cout<<k;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
