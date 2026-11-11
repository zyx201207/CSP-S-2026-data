#include<bits/stdc++.h>
using namespace std;

long long n,m,a[500005],ans=0;

vector<long long> b;
vector<long long> l;


long long f(long long x){
	long long id=x;
	long long sum=m,ant=l[x];
	for(int i=id-1;i>=0;i--){//n
		if(b[x]-b[i]<=sum){
			long long w=min(sum/(b[x]-b[i]),l[i]);
			ant+=w;
			sum-=(b[x]-b[i])*w;
		}else{
			break;
		}
	}
	return ant;
}

long long read(){
	long long xx=0,f=1;
	char c=getchar();
	while(c<'0'||'9'<c){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&'9'>=c){
		xx=(xx*10)+(long long)(c-'0');
		c=getchar();
	}
	return f*xx;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(long long i=1;i<=n;++i){//n
		a[i]=read();
	}
	sort(a+1,a+n+1);
	long long len=1;
	b.push_back(a[1]);
	l.push_back(1);
	for(int i=2;i<=n;++i){//n
		if(b[len-1]!=a[i]){
			b.push_back(a[i]);
			l.push_back(1);
			++len;
		}else{
			++l[len-1];
		}
	}
	for(long long i=0;i<len;++i){//n
		long long x=f(i);
		ans=max(ans,x);
	}
	cout<<ans;
	return 0;
}
