#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int flag;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c){
		flag=1;
		cout<<0;
	}else{
		cout<<1;
	}
	if(!flag&&(int(b[0])*10+int(b[1])==int(d[0])*10+int(d[1]))){
		cout<<1;
	}else{
		flag=1;
		cout<<0;
	}
	if(!flag&&((b[2]<='C'&&d[2]<='C')||(b[2]>='D'&&d[2]>='D'))){
		cout<<1;
	}else{
		flag=1;
		cout<<0;
	}
	if(!flag&&(abs(int(b[2])-int(d[2]))==1)){
		cout<<1;
	}else{
		flag=1;
		cout<<0;
	}
	return 0;
} 
