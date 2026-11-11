#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
char l[4]={'A','B','C'},m[4]={'D','F'};
int o=0,p=0,q=0,r=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1])cout<<1;
	else {cout<<"0000";
	return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]){cout<<1;
	
	}
	else cout<<0;
	if(b[0]==d[0]&&b[1]==d[1]){
for(int i=0;i<3;i++){
	if(b[2]==l[i]){
		o=1;r=i;
	}
	if(d[2]==l[i]){
		p=1;q=i;
	}
}
if(p==o)cout<<1;
else cout<<0;
if(o==0&&p==0){
	cout<<1;
}
else if(abs(r-q)==2){
	cout<<0;
}
else cout<<1;
	}
	else cout<<"00";
	return 0;
}
