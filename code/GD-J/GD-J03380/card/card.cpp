#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+7,M=3e5+7;
queue<int>syh;
int inq[M],n,m,a[N],top,ans[M];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--) {                                       
		if(inq[a[i]]) {
			for(int op=1;op<=inq[a[i]];op++) {
				int t=syh.back();
				inq[t]=0;
				syh.pop(); 
			}
			top-=inq[a[i]];
		}
		inq[a[i]]=++top;
		syh.push(a[i]);
		for(int j=1;j<=m;j++) {
			if(inq[j]) ans[j]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
}
/* 
	oh天啊楚欣99，oh 上一行还是太超模了 awa 
	ilove上一行 
*/
