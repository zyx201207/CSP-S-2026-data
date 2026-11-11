#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
long long n,cnt;
struct node{
	int a;
	char c;
}t[N];
string s,v;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t[i].a;
		cin>>t[i].c;
	}
	if(n<=1){
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=t[i].a;j++){
			s+=t[i].c;
		}
	}
	for(int i=s.size()-1;i>=0;i--){
		v+=s[i];
	}
	if(s==v){
		cout<<"0";
		return 0;
	}
	string x,y;
	for(int i=0;i<s.size()/2;i++){
		x+=s[i];
	}
	for(int i=s.size()-1;i>=s.size()/2;i--){
		y+=s[i];
	}
	for(int i=0;i<s.size()/2;i++){
		if(x[i]!=y[i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
