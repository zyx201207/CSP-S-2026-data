#include<bits/stdc++.h>
using namespace std;
string x,y,c,s;
string a,b;
char n,m;
int sum,cnt;
bool f,e,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>x>>y>>c>>s;
	if(x==c){
		cout<<1;
		e=1;
	}
	else{
		cout<<0;
	}
	for(int i=0;i<y.size();i++){
		if(y[i]>='0'&&y[i]<='9'){
			a=a+y[i];
		}
		else n=y[i];
	}
	sum=n;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			b=b+s[i];
		}
		else m=s[i];
	}
	cnt=m;
	if(a==b&&e==1){
		cout<<1;
		d=1;
	}
	else
	{
		cout<<0;
	}
	if(n>='A'&&n<='C'&&m>='A'&&m<='C'&&d==1||n>='D'&&n<='F'&&m>='D'&&m<='F'&&d==1){
		cout<<1;
		f=1;
	}
	else
	{
		cout<<0;
	}
	if(f==1&&abs(sum-cnt)==1){
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
} 
