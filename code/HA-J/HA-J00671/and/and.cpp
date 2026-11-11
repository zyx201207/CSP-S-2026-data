#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

const int N=200005;

int n,m;
int a[N];
int vis[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int ans=0;
	for(int j=30;j>=0;j--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(vis[i])continue;
			if((a[i]>>j)&1)++cnt;
		}
		if(cnt>=m){
			ans|=(1<<j);
			for(int i=1;i<=n;i++){
				if(vis[i])continue;
				if((a[i]>>j)&1)continue;
				vis[i]=1;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
