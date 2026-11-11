#include<bits/stdc++.h>
using namespace std;
char ans[5];
bool flag;
void f(){
	cout<<ans[1]<<ans[2]<<ans[3]<<ans[4];
  return ;
}
int  main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	ans[1]=(a==c) ? '1' : '0';
	flag  =(a==c) ? 1 : 0;
	if(!flag){
		ans[2]=ans[3]=ans[4]='0';
		f(); return 0;
	}
	if(flag && (b[0]==d[0] && b[1]==d[1])){
		ans[2]='1';
		flag=1;
	}
	else {
		ans[2] = '0';
		flag=0;
		ans[3]=ans[4]='0';
		f();
		return 0;
	}
 //cout<<ans[1]<<ans[2];	
	if((b[2]<='C' && d[2]<='C') || (b[2]>='D' && d[2]>='D'))
	  ans[3]='1';
	else {
		ans[3]=ans[4]='0';
		f(); return 0;
	}
	int x=b[2]-'A',y=d[2]-'A';
	//cout<<x-y<<" ";
	if(abs(x-y)!=1){
		ans[4]='0';
	}else ans[4]='1';
	f();
	return 0;
} 
