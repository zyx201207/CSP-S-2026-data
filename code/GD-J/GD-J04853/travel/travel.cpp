#include<bits/stdc++.h>
using namespace std;
int e,f;
int a,b;
string c,d;
int num,sum;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string c,d;
	cin>>a>>c>>b>>d;
	if(c[0]!='0'){
		e=(c[0]-'0')*10+c[1]-'0';
	}else {
		e=c[1]-'0';
	}if(d[0]!='0'){
		f=(d[0]-'0')*10+c[1]-'0';
	}else {
		f=d[1]-'0';
	}
	num=c[2]-'A'+1;
	sum=d[2]-'A'+1;
	if(a==b)cout<<1;
	else {cout<<"0000";return 0;}
	if(e==f)cout<<1;
	else {cout<<"000";return 0;}
	if((num<=3&&sum<=3)||(num>3&&sum>3))cout<<1;
	else {
		cout<<"00";
		return 0;
	}
	if(abs(num-sum)==1)cout<<1;
	else {
		cout<<"0";
		return 0;
	}
	return 0;
}
