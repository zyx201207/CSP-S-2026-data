//T3按位与 (贪心） （&） 
//long long  改  long long 
#include<bits/stdc++.h>
using namespace std;
const long long MAXN=2*1e5+5;
long long z[MAXN];
long long n,m,ans;
struct D{
	string s;
	long long xia;
}as[MAXN];

string rejin(long long a,string s){
	string c;
	while(a>=2){
		c=char(a%2+int('0'))+c;
		a/=2;
	}
	c=char(a+int('0'))+c;
	return c;
}//O(30)

bool cmp1(D t,D b){
	if(t.s.size()!=b.s.size()) return t.s.size()>b.s.size();
	else for(long long i=0;i<t.s.size();++i){
		if(t.s[i]!=b.s[i]) return t.s[i]>b.s[i];
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;++i){
		cin>>z[i];
	}
	for(long long i=1;i<=n;++i){
		as[i].s=rejin(z[i],""),as[i].xia=i;
	}
	sort(as+1,as+n+1,cmp1);
	for(long long i=1;i<=m;++i){
		if(i==1) ans=z[as[i].xia];
		else ans&=z[as[i].xia];
	}
	cout<<ans;
	return 0;
}
