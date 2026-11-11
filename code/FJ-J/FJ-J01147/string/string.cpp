#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
ll ans;
deque<array<int,2>> q;
void solve(){
	scanf("%d",&n);
	for(int i=1,l;i<=n;i++){
		scanf("%d",&l);
		char ch=getchar();
		while(ch<'a'||'z'<ch)
			ch=getchar();
		q.push_back({l,ch});
	}
	while((int)q.size()>=2){
		array<int,2> f=q.front(),b=q.back();
		q.pop_front();
		q.pop_back();
		int t=min(f[0],b[0]);
		ans+=t*(f[1]!=b[1]);
		f[0]-=t,b[0]-=t;
		if(f[0])
			q.push_front(f);
		if(b[0])
			q.push_back(b);
	}
	printf("%lld",ans);
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T=1;
//	scanf("%d",&T);
	for(;T;T--) solve();
}

