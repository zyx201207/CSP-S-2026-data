#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string a,b;
	int c,d;
	cin>>c>>a>>d>>b;
	if(c==d){
		cout<<1;
	}
	else{
		string yu="0000";
		cout<<yu;
		return 0;
	}
	int sum1=(a[0]-'0')*10+(a[1]-'0');
	int sum2=(b[0]-'0')*10+(b[1]-'0');
	if(sum1==sum2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	char o=a[2],p=b[2];
	if((o>='A'&&o<='C')&&(p>='A'&&p<='C')&&(sum1==sum2)){
		cout<<1;
	}
	else if((o>='D'&&o<='F')&&(p>='D'&&p<='F')&&(sum1==sum2)){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(o=='A'&&p=='B'&&(sum1==sum2)){
		cout<<1;
	}
	else if(o=='B'&&p=='C'&&(sum1==sum2)){
		cout<<1;
	}
	else if(o=='D'&&p=='F'&&(sum1==sum2)){
		cout<<1;
	}
	else if(p=='A'&&o=='B'&&(sum1==sum2)){
		cout<<1;
	}
	else if(p=='B'&&o=='C'&&(sum1==sum2)){
		cout<<1;
	}
	else if(p=='D'&&o=='F'&&(sum1==sum2)){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
