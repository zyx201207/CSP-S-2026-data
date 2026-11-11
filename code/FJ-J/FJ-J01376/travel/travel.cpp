#include<bits/stdc++.h>
using namespace std;
#define ll long long

int l007[]={711,712,713,721,189,722};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string rr,xx;
	cin>>a>>rr>>b>>xx;
	if(a!=b){
		cout<<"0000"<<endl;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	int r,x,rc,xc;
	r=rr[0]*10+rr[1];
	x=xx[0]*10+xx[1];
	rc=l007[rr[2]-'A'];
	xc=l007[xx[2]-'A'];
	if(r!=x){
		cout<<"1000"<<endl;
	}
	else if(rc/10!=xc/10){
		cout<<"1100"<<endl;
	}
	else if(abs(rc-xc)!=1){
		cout<<"1110"<<endl;
	}
	else if(rc!=xc){
		cout<<"1111"<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

