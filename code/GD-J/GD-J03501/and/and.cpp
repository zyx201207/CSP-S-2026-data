#include<bits/stdc++.h>
using namespace std;
string fun(int a){
	stack<int>st;
	while(a){
		st.push(a%2);
		a/=2;
	}string ans="";
	while(!st.empty()){
		ans+=char(st.top()+'0');
		st.pop();
	}return string(32-ans.length(),'0')+ans;
}int pow(int a,int b){
	int ans=1;
	for(int i=0;i<b;i++){
		ans*+a;
	}return ans;
}int funn(int a){
	int ans=0;
	int t=1;
	while(a){
		if(a%10==1)ans+=t;
		a/=10;
		t*=2; 
	}return ans;
}int stooi(string a){
	int ans=0;
	for(int i=0;i<a.length();i++){
		int t=a[i]-'0';
		ans=ans*10+t;
	}return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int c[a];
	for(int i=0;i<a;i++){
		cin>>c[i];
	}string d[a];
	for(int i=0;i<a;i++){
	    d[i]=fun(c[i]);
	}int high=-1;
	string ans="00000000000000000000000000000000";
	for(int i=0;i<32;i++){
		int cnt=0;
		for(int j=0;j<a;j++){
			if(d[j][i]=='1')cnt++;
		}
		if(cnt>=b){
			if(high==-1){
				high=i;
			}
			ans[i]='1';
		}
	}
	string anss=ans.substr(high,32-high+1);
	int ansss=stooi(anss);
	cout<<funn(ansss);
	return 0;
}
