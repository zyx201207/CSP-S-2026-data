#include <bits/stdc++.h>
using namespace std;
struct Str{
	long long num;
	char w;
}str[200020];
bool check(long long n,Str str[]){
	for(int i=1;i<=n;i++) if(str[i].w!=str[i-1].w) return false;
	return true;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long n,a,cnt=0;
	char c;
	bool s=false;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		str[i].num=a;
		str[i].w=c;
	}
	if(n%2==1) n+=1;
	for(int i=1;i<=n/2;i++){
		if(check(n,str)){
			s=true;
			cout<<0;
			break;
		}
		else if(str[i].w!=str[n-i+1].w){
			cnt+=min(str[i].num,str[n-i+1].num);
			long long p=abs(str[i].num-str[n-i+1].num);
			if(str[i].w!=str[n-i].w) cnt+=p;
		}
	}
	if(!s) cout<<cnt;
	return 0;
}
