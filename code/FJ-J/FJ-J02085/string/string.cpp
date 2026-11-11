#include<bits/stdc++.h>
using namespace std;
const long long maxn=2e5+5;
long long n;
long long ucnt,dcnt,ans;
long long s[maxn];
char ch[maxn];
long long minn(long long a,long long b){
	if(a<b) return a;
	return b;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(long long i=1;i<=n;i++) cin>>s[i]>>ch[i];
	ucnt=s[1];
	dcnt=s[n];
	long long u=1,d=n;
	while(u<=d){
		if(ch[u]!=ch[d]){
			long long ttt=minn(ucnt,dcnt);
			ucnt-=ttt;
			dcnt-=ttt;
			ans+=ttt;
			if(ucnt==0) u++,ucnt=s[u];
			if(dcnt==0) d--,dcnt=s[d];
		}
		else{
			long long ttt=minn(ucnt,dcnt);
			ucnt-=ttt;
			dcnt-=ttt;
			if(ucnt==0) u++,ucnt=s[u];
			if(dcnt==0) d--,dcnt=s[d];
		}
	}
	cout<<ans;
	return 0;
}
//Trick||Treat!
