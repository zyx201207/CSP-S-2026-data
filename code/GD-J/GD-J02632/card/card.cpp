#include<bits/stdc++.h>
using namespace std;
long long n,m,q;
long long a[500005];
long long wz[300005];
long long lj[300005];
long long p[3000005];
long long cnt[3000005];
long long h[500005];//第i个及以后第一个能找到另一半的位置 
void f(long long x){
	while(x<=n){
		while(lj[x]==-1){
			if(p[a[x]]!=q) cnt[a[x]]++;
			p[a[x]]=q;
			x++;
			if(x>n) break;
		}
		if(x>n) break;
		while(lj[x]!=-1) x=lj[x];
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	h[n+1]=-1;
	for(int i=n;i>=1;i--){
		if(wz[a[i]]==0){
			lj[i]=-1;
			h[i]=h[i+1];
		}
		else{
			lj[i]=wz[a[i]];
			if(h[i+1]==-1)h[i]=i;
			else{
				if(lj[i]<lj[h[i+1]]){
					h[i]=i;
				}
				else h[i]=h[i+1];
			}
		}
		wz[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		q=i;
		f(i);
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
}
