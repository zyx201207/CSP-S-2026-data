#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int p[7];
int q[7];
char m,n;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	for(int i=1;i<=3;i++){
		if(b[i]>='0'&&b[i]<='9'){
			p[i]=b[i];
		}
		if(b[i]>='A'&&b[i]<='F'){
			m=b[i];
		}
	}
	for(int i=1;i<=3;i++){
		if(d[i]>='0'&&d[i]<='9'){
			q[i]=d[i];
		}
		if(d[i]>='A'&&d[i]<='F'){
			n=d[i];
		}
	}
	if(a==c){
		cout<<"1";
	}
	if(a!=c){
		cout<<"0000";
		return 0;
	}
	if(p[1]==q[1]&&p[2]==q[2]){
		cout<<"1";
	}
	if(m>='A'&&m<='C'&&n>='A'&&n<='C'){
		cout<<"1";
	}
	else if((m=='D'&&n=='F')||(m=='F'&&n=='D')){
		cout<<"11";
	}
	if((int(m-n)==1||int(n-m)==1)){
		cout<<"1";
	}
	if((m=='C'&&n=='D')||(n=='D'&&m=='C')){
		cout<<"0";
	}
	else{
		cout<<"0";
	}
	return 0;
}
