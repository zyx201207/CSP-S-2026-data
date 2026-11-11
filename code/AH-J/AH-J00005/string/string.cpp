#include<iostream>
#include<cstdio>
using namespace std;
int x;
string s;
char c;
int n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		cin>>c;
		for(int i=1;i<=x;i++) s=s+c;
	}
	//cout<<s;
	int l=1,r=s.size(),cnt=0;
	s=' '+s;
	while(l<=r){
		if(s[l]!=s[r]) cnt++;
		l++,r--;
	}
	cout<<cnt;
}
