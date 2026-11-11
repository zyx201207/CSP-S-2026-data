#include <bits/stdc++.h>
using namespace std;
constexpr int N=5e5+5,M=3e5+5;
static int read(){
	int ans=0;
	char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9'){
		ans=ans*10+(ch&15);
		ch=getchar();
	}
	return ans;
}
int n,m,a[N],cnt[M];
bool tong[M];
vector<int>t;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read();m=read();
	for (int i=1;i<=n;++i) a[i]=read();
	for (int k=1;k<=n;++k){
		int maxx=0;
		for (int i=k;i<=n;++i){
			if (tong[a[i]]){
				while (t[t.size()-1]!=a[i]){
					tong[t[t.size()-1]]=0;
					t.pop_back();
				}
				tong[a[i]]=0;
				t.pop_back();
			}
			t.push_back(a[i]);
			tong[a[i]]=1;
			maxx=max(maxx,a[i]);
		}
		for (auto v:t) ++cnt[v];
		t.clear();
		for (int i=1;i<=maxx;++i) tong[i]=0;
	}
	for (int i=1;i<=m;++i) printf("%d ",cnt[i]);
	return 0;
}
