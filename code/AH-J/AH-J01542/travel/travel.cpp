#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	int sum1=0,sum2=0;
	char c1,c2;
	sum1=(b[0]-'0')*10+b[1]-'0';
	c1=b[2];
	sum2=(d[0]-'0')*10+d[1]-'0';
	c2=d[2];
	if(a==c)cout<<1;
	else{
		cout<<"0000"<<endl;
		return 0;
	}
	if(sum1==sum2)cout<<1;
	else{
		cout<<"000"<<endl;
		return 0;
	}
	if(c1=='A'&&c2=='B'||c2=='A'&&c1=='B'||c1=='A'&&c2=='C'||c2=='A'&&c1=='C'||c1=='B'&&c2=='C'||c2=='B'&&c1=='C'||c1=='D'&&c2=='F'||c2=='D'&&c1=='F'){
		cout<<1;
	}
	else{
		cout<<"00"<<endl;
		return 0;
	}
	if(c1=='A'&&c2=='B'||c1=='B'&&c2=='A'||c1=='B'&&c2=='C'||c1=='C'&&c2=='B'||c1=='D'&&c2=='F'||c1=='F'&&c2=='D'){
		cout<<1<<endl;
	}
	else cout<<0;
	return 0;
} 
