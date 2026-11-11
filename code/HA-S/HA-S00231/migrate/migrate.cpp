#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t;

ll n,d;
ll x[2000010];

ll dis[5010][5010];
ll dp1[5010],dp2[5010];

ll te[200010],la[200010];
ll bg[2000010],ed[2000010];

ll mxr[2000010];
void build(int l,int r,int p){
	if(l==r){
		te[p]=0;
		return;
	}
	la[p]=0;
	int mid=l+(r-l)/2;
	build(l,mid,p*2);
	build(mid+1,r,p*2+1);
	te[p]=te[p*2]+te[p*2+1];
	return;
}

void update(int l,int r,int s,int t,int p,ll v){
	if(t<s) return;
	if(s<=l && r<=t){
		la[p]+=v;
		te[p]+=(r-l+1)*v;
		return;
	}
	int mid=l+(r-l)/2;
	if(la[p]){
		la[p*2]+=la[p];
		la[p*2+1]+=la[p];
		te[p*2]+=(mid-l+1)*la[p];
		te[p*2+1]+=(r-mid)*la[p];
		la[p]=0;
	}
	if(s<=mid){
		update(l,mid,s,t,p*2,v);
	}
	if(mid<t){
		update(mid+1,r,s,t,p*2+1,v);
	}
	te[p]=te[p*2]+te[p*2+1];
	return;
}

ll query(int l,int r,int x,int p){
	if(x<l || x>r) return 0;
	if(l==r && l==x){
		return te[p];
	}
	int mid=l+(r-l)/2;
	if(la[p]){
		la[p*2]+=la[p];
		la[p*2+1]+=la[p];
		te[p*2]+=(mid-l+1)*la[p];
		te[p*2+1]+=(r-mid)*la[p];
		la[p]=0;
	}
	if(x<=mid){
		return query(l,mid,x,p*2);
	}else{
		return query(mid+1,r,x,p*2+1);
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cin >> c >> t;
	while(t-->0){
		cin >> n >> d;
		for(int i=1;i<=n;++i){
			cin >> x[i];
		}
		for(int i=1;i<=n;++i){
			int st=1,now=i;
			int k=n+1;
			for(int j=i+1;j<=n;++j){
				if(now==j-1 && x[j]-x[now]>d){
					k=j;
					break;
				}
				if(x[j]-x[now]>d){
					++st;
					now=j-1;
					if(now==j-1 && x[j]-x[now]>d){
						k=j;
						break;
					}
				}
				dis[i][j]=st;
			}
			for(;k<=n;++k){
				dis[i][k]=-1;
			}
		}
		for(int i=1,j=1;i<=n;++i){
			while(j<=n && x[j]-x[i]<=d){
				++j;
			}
			mxr[i]=j-1;
		}
		ll ans=0;
		for(int i=1;i<=n;++i){
			for(int j=0;j<=n-i+1;++j){
				bg[j]=1e9;
				ed[j]=0;
			}
			for(ll j=i+1;j<=n;++j){
				dp1[j]=dis[i][j];
				if(dp1[j]==-1) continue;
				bg[dp1[j]]=min(bg[dp1[j]],j);
				ed[dp1[j]]=max(ed[dp1[j]],j);
			}
			dp1[i]=0;
			build(i,n,1);
			update(i,n,i,i,1,1);
			for(int j=i;j<=n;++j){
				if(dp1[j]==-1) break;
//				for(int k=j+1;k<=n && x[k]-x[j]<=d;++k){
//					if(dp1[j]+1==dp1[k]){
//						dp2[k]+=dp2[j];
//					}
//				}
				ll tmp=query(i,n,j,1);
				update(i,n,bg[dp1[j]+1],min(ed[dp1[j]+1],mxr[j]),1,tmp);
				if(tmp==2) ++ans;
			}
//			for(int j=i+1;j<=n;++j){
//				if(dp2[j]==2){
//					++ans;
//				}
//			}
		}
		cout << ans << '\n';
	}
	return 0;
}
// final ver.
