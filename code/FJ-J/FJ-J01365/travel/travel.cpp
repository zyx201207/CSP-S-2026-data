#include<bits/stdc++.h>
typedef  long long  ll;
using namespace std;
ll c1,s1,c2,s2;
char s3,s4;
bool a=0,b=0,c=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>s3>>c2>>s2>>s4;
	if(c1==c2){
		a=1;
		cout<<1;
	}
	else cout<<0;
	if(a==1&&s1==s2){
		b=1;
		cout<<1;
	}
	else cout<<0;
	if(s3>s4)swap(s3,s4);
	if(b==1&&((s3>='A'&&s3<='C'&&s4>='A'&&s4<='C')||(s3=='D'&&s4=='F'))){
		c=1;
		cout<<1;
	}
	else cout<<0;
	if(c==1&&(char(s3+1)==s4||s3=='D'&&s4=='F')){
		cout<<1;
	}
	else cout<<0;
	return 0;
}
