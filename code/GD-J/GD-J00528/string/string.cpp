#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int n;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;++i){
		int a;
		char c;
		cin>>a>>c;
		char *t=new char[a+1];
		memset(t,c,a);
		t[a]=0;
		s+=t;
		delete t;
	}
	int ans=0,len=s.length();
	for(int i=0;i<(len>>1);++i){
		if(s[i]!=s[len-i-1]){
			s[len-i-1]=s[i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
