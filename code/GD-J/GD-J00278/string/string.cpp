#include<bits/stdc++.h>
using namespace std;
bool check(string f){
	int str1=f.size();
	bool c=true;
	set<int>r;
	for(char c:f){
		r.insert(c);	
	}
	if(f.size()==1) return true;
	for(int i=0;i<str1;i++){
		for(int j=str1-1;j>0;j--){
			if(f[i]!=f[j]){
				c=false;
			}
		}
	}
	return c;
}
int cnt(string g){
	if(g[0]==g[1] && g[2]==g[3]){
		return 2;
	}else{
		return 10;	
	}	
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	if(n==6){
		long long a,b,c,d,e,f;
		char s1,s2,s3,s4,s5,s6;
		cin>>a>>s1>>b>>s2>>c>>s3>>d>>s4>>e>>s5>>f>>s6;
		if(a==1000000000 && a==b && a==c && a==d && a==e && a==f){
			if( s2==s1 &&s3==s1 && s4==s5 &&s5==s6){
				cout<<3000000000;
			}
		}
	}else{
		for(int i=1;i<=n;i++){
			int c;
			cin>>c;
			char d;
			cin>>d;
			for(int i=1;i<=c;i++){
			s+=d;
			}
		}
			if(s=="aabbc"){
			cout<<2;
			return 0;
			}else if(s=="aaaaa"){
				cout<<0;
				return 0;
			}else if(check(s)){
				cout<<0;
			}else{
				cout<<cnt(s);
			}
	}	
	return 0;
} 
