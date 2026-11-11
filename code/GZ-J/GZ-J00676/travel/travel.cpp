//准考证号：GZ-J00676 学校：遵义市播州区实验学校 姓名：卢煜晨 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,n,m;
	string c="",d="";
	cin>>a;
	cin>>c;
	cin>>b;
	cin>>d;
	n=char(c[2]);
	m=char(d[2]);
	if(a==b){
		cout<<"1";
	}else if(a!=b){
		cout<<"0000";
		return 0;
	}
	if(c[0]==d[0]&&c[1]==d[1]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if(n<=67&&m<=67){
		cout<<"1";
	}else if(n>=67&&m>=67){
		cout<<"1";
	}else if(n>=67&&m<=67){
		cout<<"00";
		return 0;
	}else if(m>=67&&n<=67){
		cout<<"00";
		return 0;
	}
	if(n-m==1||n-m==-1){
		cout<<"1";
	}else{
		cout<<"0";
	}
}
