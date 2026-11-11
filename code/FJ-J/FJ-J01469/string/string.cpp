#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10,INF=LLONG_MAX,P=13331;
int read(){
	int x=0,f=1;
	char c=getchar();
	while('0'>c||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x<10)putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
int n,cnt,ans;
pair<int,char>p[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		int a=read();
		char c;
		cin>>c;
		if(p[cnt].second==c)p[cnt].first+=a;
		else p[++cnt]=make_pair(a,c);
	}
	int l=1,r=cnt;
	while(l<r){
		int d=min(p[l].first,p[r].first);
		p[l].first-=d;
		p[r].first-=d;
		if(p[l].second!=p[r].second)ans+=d;
		if(!p[l].first)l++;
		if(!p[r].first)r--;
	}
	write(ans);
}
