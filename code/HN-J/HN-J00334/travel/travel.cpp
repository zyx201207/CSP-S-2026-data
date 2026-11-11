#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
using namespace std;
string s1,s2;
string t1,t2;
int num1,num2;
char c_1,c_2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s1>>s2>>t1>>t2;
	for(int i=0;i<s2.size();i++){
		if(s2[i]>='0'&&s2[i]<='9'){
			num1=num1*10+s2[i]-'0';
		}else{
			c_1=s2[i]; 
			break;
		}
	}
	for(int i=0;i<t2.size();i++){
		if(t2[i]>='0'&&t2[i]<='9'){
			num2=num2*10+t2[i]-'0';
		}else{
			c_2=t2[i];
			break;
		}
	}
	if(s1==t1){
		cout<<1;
	}else{
		cout<<0;
	}
	if(s1==t1&&num1==num2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(s1==t1&&num1==num2&&(c_1>='A'&&c_1<='C'&&c_2>='A'&&c_2<='C')||(c_1>='D'&&c_1<='F'&&c_2>='D'&&c_2<='F')){
		cout<<1;
	}else{
		cout<<0;
	}
	if(s1==t1&&num1==num2&&((c_1=='A'&&c_2=='B')||(c_1=='B'&&c_2=='C')||(c_1=='D'&&c_2=='F') || (c_2=='A'&&c_1=='B')||(c_2=='B'&&c_1=='C')||(c_2=='D'&&c_1=='F'))){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
