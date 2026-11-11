#include<bits/stdc++.h>
using namespace std;
//ÎÄ¼þ²Ù×÷  long long
bool hw(string x){
	string t="";
	for(int i=x.size()-1;i>=0;--i){
		t+=x[i];
	}
	return x==t;
}
long long a[200005];
char c[200005];
int main(){	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	long long L=0;
	long long cnt=0;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];++j){
			s+=c[i];
		}
	}
	if(hw(s)){
		cout<<0;
		return 0;
	}
	else{
		for(int i=0,j=s.size()-1;i<=s.size()-1,j>=0;++i,--j){
			if(s[i]!=s[j]){
				cnt++;
			}
		}
	}
	cout<<cnt/2;
	return 0;
}
