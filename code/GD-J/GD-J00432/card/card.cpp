#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
const int M = 3e5+5;
int n,m;
int a[N];
long long cnt[M];

bool pd() {
	for(int i=1;i<=n;i++) {
		if(a[i]>a[i-1]) {
			return false;
		}
	}
	return true;
}

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	
	if(n<=7000) {
		int c[7005],pos[7007];
		bool vis[7005];
		for(int i=1;i<=n;i++) {
			memset(c,0,sizeof(c));
			memset(pos,0,sizeof(pos));
			memset(vis,false,sizeof(vis));
			stack<int>st;
			for(int j=i;j<=n;j++) {
				if(vis[a[j]]) {
					while(!st.empty() && st.top()!=a[j]) {
						vis[st.top()]=false;
						st.pop();
					}
				}
				else {
					vis[a[j]]=true;
					st.push(a[j]);
				}
			}
			
			while(!st.empty()) {
//				cout<<st.top()<<' ';
				cnt[st.top()]++;
				st.pop();
			}
//			cout<<endl;
		}
		
		for(int i=1;i<=m;i++) {
			printf("%lld ",cnt[i]);
		}
	}
	
	else if(pd()) {
		for(long long i=1;i<=n;i++) {
			cnt[a[i]]=max(cnt[a[i]],i);
		}
		
		for(int i=1;i<=m;i++) {
			printf("%lld ",cnt[i]);
		}
	}
	
	else {
		int c[10005],pos[10007];
		bool vis[10005];
		for(int i=1;i<=n;i++) {
			memset(c,0,sizeof(c));
			memset(pos,0,sizeof(pos));
			memset(vis,false,sizeof(vis));
			stack<int>st;
			for(int j=i;j<=n;j++) {
				if(vis[a[j]]) {
					while(!st.empty() && st.top()!=a[j]) {
						vis[st.top()]=false;
						st.pop();
					}
				}
				else {
					vis[a[j]]=true;
					st.push(a[j]);
				}
			}
			
			while(!st.empty()) {
//				cout<<st.top()<<' ';
				cnt[st.top()]++;
				st.pop();
			}
//			cout<<endl;
		}
		
		for(int i=1;i<=m;i++) {
			printf("%lld ",cnt[i]);
		}
	}
	return 0;
}
