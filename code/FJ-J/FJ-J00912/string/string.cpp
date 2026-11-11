#include <bits/stdc++.h>
using namespace std;
struct pos{
	long long s,e;
	char c;
}s[200005];
long long n,sum,cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++){
		int a;
		char b;
		cin>>a>>b;
		s[i].s = sum+1;
		sum+=a;
		s[i].e = sum;
		s[i].c = b;
		
	}
	long long l = 0,r = sum+1,a = 1,b = n;
	while(l<r && a<b){
		int t = min(s[a].e-l,r-s[b].s);
		if(s[a].c != s[b].c)cnt+=t;
		l+=t,r-=t;
		if(l == s[a].e)a++;
		if(r == s[b].s)b--;
	}
	cout <<cnt<<"\n";
	return 0;
}
