#include<bits/stdc++.h> 
using namespace std;
long long n,ans=LLONG_MAX/3,len_,len,len2;
char c;
string s="";
string zfj="";
bool ishw(string ss){
	string fanl="";
	len_=ss.size();
	for(long long i=len_-1;i>=0;i--){
		fanl+=ss[i];
	}
	return fanl==ss;
}
void dfs(long long dep,long long anss){
	if(dep==len){
		if(ishw(s)){
			ans=min(ans,anss);
		}
		return;
	}
	char c=s[dep];
	dfs(dep+1,anss);
	for(int i=0;i<len2;i++){
		if(zfj[i]!=c){
			s[dep]=zfj[i];
			dfs(dep+1,anss+1);
		}
	}
	s[dep]=c;
	return;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int x,i=1;i<=n;i++){
		scanf("%lld",&x);
		c=getchar();
		while(c==' '||c=='\t'||c=='\r'){
			c=getchar();
		}
		zfj+=c;
		while(x--){
			s+=c;
		}
	}
	len=s.size();
	len2=zfj.size();
	dfs(0,0);
	printf("%lld",ans);
	return 0;
}
