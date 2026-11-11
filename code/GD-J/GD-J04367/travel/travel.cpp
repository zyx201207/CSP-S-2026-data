#include<bits/stdc++.h>
#define int long long
using namespace std;
string a,b,c,d;
int num1=0,num2=0;
int cnt1=0,cnt2=0;
char q,w;
int ans[10];
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>a>>b>>c>>d;
	if(a[0]=='0'){
		num1=a[1]-'0';
	}
	else{
		num1=(a[0]-'0')*10+(a[1]-'0');
	}
	if(b[0]=='0'){
		cnt1=b[1]-'0';
	}
	else{
		cnt1=(b[0]-'0')*10+(b[1]-'0');
	}
	q=b[2];
	if(c[0]=='0'){
		num2=c[1]-'0';
	}
	else{
		num2=(c[0]-'0')*10+(c[1]-'0');
	}
	if(d[0]=='0'){
		cnt2=d[1]-'0';
	}
	else{
		cnt2=(d[0]-'0')*10+(d[1]-'0');
	}
	w=d[2];
	if(num1!=num2){
		cout<<"0000";
	}
	else{
		if(cnt1!=cnt2){
			cout<<"1000";
		}
		else{
			if((q>='A'&&q<='C'&&w>='A'&&w<='C')||((q>='D'&&w>='D'))){
				if(q>w)swap(q,w);
				if((q=='A'&&w=='B')||(q=='B'&&w=='C')||(q=='D'&&w=='F')){
					cout<<"1111";
				}
				else{
					cout<<"1110";
				}
			}
			else{
				cout<<"1100";
			}
		}
	}
	return 0;
}
