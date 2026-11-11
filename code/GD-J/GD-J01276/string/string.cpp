#include<iostream>
#include<cstdio>
using namespace std;
long long n,a,cnt=0;
string s;
char ch;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>ch;
		for(int j=0;j<a;j++) s=s+ch;
	}
	int len=s.size();
	int iii1=0,jjj1=len-1;
	while(iii1<jjj1){
		if(s[iii1]!=s[jjj1]) cnt++;
		iii1++;
		jjj1--;
	}
	cout<<cnt;
	return 0;
}
