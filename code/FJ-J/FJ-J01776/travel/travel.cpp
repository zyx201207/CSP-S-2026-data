#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a1,a2,b1,b2;
char c1,c2;
LL read(){
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	LL ans=c-'0';
	c=getchar();
	ans=ans*10+c-'0';
	return ans;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	a1=read();
	b1=read();
	c1=getchar();
	a2=read();
	b2=read();
	c2=getchar();
	if(c1=='F')c1--; 
	if(c2=='F')c1--; 
	if(a1==a2){
		cout<<"1";
		if(b1==b2){
			cout<<"1";
			if((c1<='C'&&c2<='C')||(c1>'C'&&c2>'C')){
				cout<<"1";
				if(abs(c1-c2)==1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
