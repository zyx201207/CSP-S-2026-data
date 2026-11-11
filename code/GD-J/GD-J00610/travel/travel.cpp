#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
const int INF=0x3f3f3f3f;
int n;
ll a[N];
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll c1,c2,num1=0,num2=0;
	string s1,s2,f1,f2;
	cin>>c1>>s1>>c2>>s2;
	for(int i=1;i<s1.size();i++){
		num1+=(a[0]+a[1]);
	}
	for(ll i=1;i<s2.size();i++){
		num2+=(a[0]+a[1]);
	}
	for(ll i=0;i<s1.size();i++){
		f1=a[3];
	}
	for(ll i=0;i<s2.size();i++){
		f2=a[2];
	}
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(num1==num2){
		cout<<1;	
	}
	else{
		cout<<0;
	}
	if(((f1=="A" && f2=="B")|| (f1=="B" && f2=="A")||(f1=="B" && f2=="C")|| (f1=="C" && f2=="B")||(f1=="C" && f2=="A")||(f1=="A" && f2=="C")||(f1=="D" && f2=="F")||(f1=="F" && f2=="D"))&&num1==num2){
			cout<<1;	
	}
	else{
		cout<<0;
	}
	if(((f1=="A"&&f2=="B") || (f1=="B"&&f2=="C") || (f1=="C"&&f2=="D") || (f1=="D"&&f2=="F") || (f2=="A"&&f1=="B") || (f2=="B"&&f1=="C") || (f2=="C"&&f1=="D") || (f2=="D"&&f1=="F")) && f1!=f2){
		cout<<1;
	}else{
		cout<<0;
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
