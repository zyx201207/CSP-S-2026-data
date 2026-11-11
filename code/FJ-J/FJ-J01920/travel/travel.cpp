#include<bits/stdc++.h>
using namespace std;
long long cc1,cc2;
string ss1,ss2,q,w,e;
int a,b,c,o;
char v,n;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cc1>>ss1>>cc2>>ss2;
    if(cc1==cc2){
    	cout<<1;
    	a=1;
	}else{
		cout<<0;
	}
	if(ss1[0]==ss2[0]&&ss1[1]==ss2[1]&&a==1){
		cout<<1;
		b=1;
	}else{
		cout<<0;
	}
	q="qABC";
	w="qDF";
	if(ss1[2]==q[1]||ss1[2]==q[2]||ss1[2]==q[3]){
		o=1;
	}
	if(ss2[2]==w[1]||ss2[2]==w[2]){
		if(o==1){
			o=0;
		}else{
			o=1;
		}
	}
	if(b==1&&o==1){
		cout<<1;
		c=1;
	}else{
		cout<<0;
	}
	if(c==1&&(ss1[2]==w[1]||ss1[2]==w[2]||ss1[2]==q[2]||ss2[2]==q[2])){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}



