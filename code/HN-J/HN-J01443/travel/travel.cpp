#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int f=0;
	if(a==c) cout<<1;
	else{
		cout<<0;
		f=1;
	}
	int t1,t2;
	t1=(b[0]-'0')*10+b[1];
	t2=(d[0]-'0')*10+d[1];
	if(t1==t2&&!f){
		cout<<1;
	}
	else{
		cout<<0;
		f=1;	
	}
	if(b[2]>d[2]) swap(b[2],c[2]);
	if(b[2]<='C'&&d[2]>='D'||f){
		f=1;
		cout<<0;
	}else cout<<1;
	char tt=b[2]+1,ttt=d[2];
	if(tt==ttt&&!f){
		cout<<1;
	}else cout<<0;
	return 0;
} 
