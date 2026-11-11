#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define down(i,x,y) for(int i=(x);i>=(y);--i)
#define mkp make_pair
#define fi first
#define se second
#define eb emplace_back
#define pb push_back
#define pii pair<int,int>
#define maxn 200005
using namespace std;
int n,m;
ll a[maxn];
int one[66];
vector<int> now;
int mx=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		scanf("%lld",a+i);
		now.eb(a[i]);
		rep(j,0,30){
			if((a[i]>>j)&1){
				mx=max(mx,j);
				++one[j];
			}
		}
	}
	down(i,mx,0){
		if(one[i]>=m){
			rep(j,0,i-1)one[j]=0;
			vector<int> tmp;
			for(int j:now){
				if((j>>i)&1){
					tmp.eb(j);
					rep(k,0,i-1){
						if((j>>k)&1)++one[k];
					}
				}
			}
			now=tmp;
		}
	}
	ll ans=now[0];
	rep(i,1,m-1){
		ans&=now[i];
	}
	printf("%lld",ans);
	return 0;
}

