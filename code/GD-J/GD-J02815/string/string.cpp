#include<bits/stdc++.h>
using namespace std;

const int N=2*1e5;

long long n,ans,strsz;
struct node{
	long long a;
	char c;
}str[N];

bool check(string s){
	long long l=s.size();
	for(int i=0;i<=l/2;i++){
		if(s[i]!=s[l-i])return false;
	}
	return true;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		long long num;
		char ch;
		cin>>num>>ch;
		if(ch==str[strsz].c) str[strsz].a+=num;
		else{
			str[++strsz].a=num;
			str[strsz].c=ch;
		}
	}
	
	if(strsz==1){
		cout<<0;
		return 0;
	}
	
	int l=1,r=strsz;
	while(l<r){
		long long stp=min(str[l].a,str[r].a);
		if(str[l].c!=str[r].c)ans+=stp;
		str[l].a-=stp;
		str[r].a-=stp;
		if(str[l].a==0)l++;
		if(str[r].a==0)r--;
	}
	
	cout<<ans;
	
	return 0;
}
