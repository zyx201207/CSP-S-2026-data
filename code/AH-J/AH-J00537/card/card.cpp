#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long LL;
LL n,m,f[N],a[N],cnt[N];
deque<LL> st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(LL i=1;i<=n;i++)cin>>a[i];
	for(LL i=1;i<=n;i++){
		st.clear();
		memset(f,0,sizeof f);
		for(LL j=i;j<=n;j++){
			if(f[a[j]]){//出现过
				while(!st.empty()&&st.back()!=a[j]){f[st.back()]=0;st.pop_back();}
			}else st.push_back(a[j]);
			f[a[j]]=1;//记录 点数i--在序列中出现
		}
		while(!st.empty()){cnt[st.back()]++;st.pop_back();}
	}
	for(LL i=1;i<=m;i++) printf("%lld ",cnt[i]);
	return 0;
}
