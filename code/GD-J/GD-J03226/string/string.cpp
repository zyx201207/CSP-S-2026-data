#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int l,x;
char c;
char str[N];
string str2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>l;
	int len=0;
	for(int i=1;i<=l;i++){
		cin>>x>>c;
		str[i]=c;
	}
	str2=str;
	int len1=str2.size()-1;
	for(int i=0;i<str2.size();i++){
		str[len--]=str2[i];
	}
	if(str==str2)cout<<0;
	return 0;
}
