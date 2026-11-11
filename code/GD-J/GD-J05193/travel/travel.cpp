#include<bits/stdc++.h>
using namespace std;
bool che(string x,string y,int n){
	for(int i=0;i<n;i++){
		if(x[i]!=y[i])return false;
	}
	return true;
}
bool e[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(che(a,c,2))e[1]=true;
	else e[1]=false;
	if(che(b,d,2)&&e[1])e[2]=true;
	else e[2]=false;
	if(e[2]&&(('A'<=b[2]&&b[2]<='C'&&'A'<=d[2]&&d[2]<='C')||('D'<=b[2]&&b[2]<='E'&&'D'<=d[2]&&d[2]<='E')))e[3]=true;
	else e[3]=false;
	if(e[3]&&abs(b[3]-d[3])==1)e[4]=true;
	else e[4]=false;
	for(int i=1;i<=4;i++){
		if(e[i])cout<<1;
		else cout<<0;
	}
	return 0;
} 
