#include<bits/stdc++.h>
using namespace std;
string a[10],b[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a[0]>>a[1];
	cin>>b[0]>>b[1];
	if(a[0]==b[0]) cout<<1;
	else cout<<0;
	
	int f=1;
	if(a[0]==b[0]){
		for(int i=0;i<2;i++) if(a[1][i]!=b[1][i]) f=0;
		if(f) cout<<1;
		else cout<<0;
	}else{
		f=0;
		cout<<0;
	}
	
	int x,y;
	if(f){
		
		if(a[1][2]=='D' || a[1][2]=='F') x=1;
		else x=0;
		if(b[1][2]=='D' || b[1][2]=='F') y=1;
		else y=0;
		if(x==y) cout<<1;
		else cout<<0;
	}else cout<<0;
	
	if(f){
		if(x==y && (a[1][2]-1==b[1][2]||a[1][2]+1==b[1][2])) cout<<1;
		else cout<<0;
	}else cout<<0;
	
	return 0;
}
