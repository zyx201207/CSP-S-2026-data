#include<bits/stdc++.h>
using namespace std;
int x,y;
string a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>x>>a>>y>>b;
	if(x==y){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(a.substr(0,2)==b.substr(0,2)){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if(a[2]<='C'&&b[2]<='C'||a[2]>='D'&&b[2]>='D'){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(a[2]=='D'&&b[2]=='F'||a[2]=='F'&&b[2]=='D'||(a[2]-b[2]==-1||a[2]-b[2]==1&&a[2]!='D'&&b[2]!='F')){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
} 
