#include<bits/stdc++.h>
using namespace std;
int is(string m){
	int slen=m.length();
	bool g=0;
	for(int i=0;i<=slen/2;i++){
		if(m[i]!=m[slen-i-1]){
			g=1;
			break;
		}
	}
	if(g==1){
		return 0;
	}else{
		return 1;
	}
}
int huang(string m){
	int mlen=m.length();
	int g=0;
	for(int i=0;i<=mlen/2;i++){
		if(m[i]!=m[mlen-i-1]){
			g++;
		}
	}
	return g;
}
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	int a;
	char c;
	for(long long i=1;i<=n;i++){
		cin>>a>>c;
		for(long long j=1;j<=a;j++){
			s+=c;
		}
	}
	if(is(s)==1){
		cout<<0<<endl;
	}else{
		cout<<huang(s)<<endl;
	}
	return 0;
} 
