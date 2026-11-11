#include <bits/stdc++.h>
using namespace std;
string x,y,n,m,s;
int a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdoout);
	cin>>x>>y>>n>>m;
	if(x==n)s+='1';
	else{
		s+='0';
	}
	for(int i=0;i<2;i++){
		a+=y[i]+a*10;
		b+=m[i]+b*10;
	}
	c=y[2]-'A'+1;
	d=m[2]-'A'+1;
	if(a==b)s+='1';
	else s+='0';
	if(((c<=3&&d<=3)||(c>3&&d>3))&&s[1]!='0'){
		s+='1';
	}
	else s+='0';
	if((c==d-1||c==d+1)&&s[2]!='0'){
		s+='1';
	}
	else s+='0';
	cout<<s;
	return 0;
}
