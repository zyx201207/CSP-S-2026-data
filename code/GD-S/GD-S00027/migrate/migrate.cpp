#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2000010;
int c,n;
int d,t;
int x[N];
vector<int> m[N];
struct ch{
	int ch;
	int times;
};
inline ch check(int l,int r){
	if(l==r){
		ch pos;
		pos.ch=1;
		pos.times=0;
		return pos;
	}
	ch ans;
	ans.ch=0;
	ans.times=1<<30;
	for(int i=l+1;i<=r;i++){
		if(x[i]-x[i-1]>d){
			ch pos; pos.ch=-1; pos.times=1<<30;
			return pos;
		}
	}
	for(int i=l+1;i<=r;i++){
		if(abs(x[i]-x[l])<=d){
			ch tex=check(i,r);
			if(tex.ch>2){
				return tex;
			}
			if(tex.times+1==ans.times)
				ans.ch=ans.ch+tex.ch;
			else if(tex.times+1<ans.times){
				ans=tex;
			}
		}
		if(ans.ch>2){
			return ans;
		}
	}
	return ans;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%d",&x[i]);
		}
		for(int i=1;i<=n;i++){
			m[i].clear();
			for(int j=0;j<=n;j++){
				m[i].push_back(0);
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(check(i,j).ch==2){
					++ans;
				}
			}
		}
		printf("%lld\n",ans);
	}
}
