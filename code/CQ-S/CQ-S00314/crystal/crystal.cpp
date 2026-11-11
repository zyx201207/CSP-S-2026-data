#include<bits/stdc++.h>
#define wef(i,l,r) for(int i=l;i<=r;i++)
#define few(i,r,l) for(int i=r;i>=l;i--)
#define pii pair<int,int>
#define int long long
#define endl cout<<"\n"
using namespace std;
using ll=long long;
const int N=5e5+5;
int a[N],pre[N];
int n,m;
inline bool check(int mid){
	deque<int> q;
	wef(i,1,mid-1){
		while(!q.empty()&&a[q.back()]<=a[i]) q.pop_back();
		q.push_back(i);
	}
	wef(i,mid,n){
		while(!q.empty()&&a[q.back()]<=a[i]) q.pop_back();
		if(i-q.front()+1>mid) q.pop_front();
		q.push_back(i);
		int maxn=a[q.front()],sum=pre[i]-pre[i-mid];
		if(maxn*mid-sum<=m) return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	wef(i,1,n) cin>>a[i];
	sort(a+1,a+1+n);
	wef(i,1,n) pre[i]=pre[i-1]+a[i];
	int l=1,r=n,res=0;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)){
			res=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<res;
	return 0;
}
