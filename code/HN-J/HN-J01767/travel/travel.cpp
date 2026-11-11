#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string x,y,u,p;
	cin>>x>>y>>u>>p;
	if(x==u){
		cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	int st=1;
	for(int i=0;i<y.size()-1;i++){
		if(y[i]!=p[i]){
			cout<<0;
			st=0;
			break;
		}
	}
	if(st==1) cout<<1;
	if(st==0){
		cout<<0<<0;
		return 0;
	}
	if(((y[2]>='A'&&y[2]<='C')&&(p[2]>='A'&&p[2]<='C'))||((y[2]=='D'||y[2]=='F')&&(p[2]=='D'||p[2]=='F'))){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(y[2]=='A'&&p[2]=='B'||y[2]=='B'&&p[2]=='A'){
		cout<<1;
	}
	else if(y[2]=='B'&&(p[2]=='A'||p[2]=='C')||p[2]=='B'&&(y[2]=='A'||y[2]=='C')){
		cout<<1;
	}
	else if(y[2]=='C'&&p[2]=='B'||y[2]=='B'&&p[2]=='C'){
		cout<<1;
	}
	else if(y[2]=='D'&&p[2]=='F'||y[2]=='F'&&p[2]=='D'){
		cout<<1;
	}
	else if(y[2]=='F'&&p[2]=='D'||y[2]=='D'&&p[2]=='F'){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
