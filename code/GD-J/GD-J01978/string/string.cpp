#include<bits/stdc++.h>
using namespace std;
bool is=true;
inline long long read(){
	long long x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long n=read();
	string s;
	while(n--){
		long long x=read();
		if(x!=1000000000)is=false;
		string c;
		cin>>c;
		while(x--)s+=c;
	}
	unsigned long long ans=0;
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1])ans++;
	}
	printf("%d",ans);
	return 0;
}

