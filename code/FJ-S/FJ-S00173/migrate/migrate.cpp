#include<bits/stdc++.h>
#define N 2000005
#define ll long long
using namespace std;
struct Data{
	int minn,cnt;
	Data operator + (const Data &opt) const {
		Data res;
		if(minn < opt.minn){
			res.minn = minn;
			res.cnt = cnt;
		}else if(minn > opt.minn){
			res.minn = opt.minn;
			res.cnt = opt.cnt;
		}else{
			res.minn = minn;
			res.cnt = cnt + opt.cnt;
		}
		return res;
	}
};
namespace SegmentTree{
	Data tri[N << 2];
	void update(int p,int l,int r,int x,Data dat){
		if(l == r){
			tri[p] = dat;
			return;
		}
		int mid = (l + r) >> 1;
		if(x <= mid){
			update(p << 1,l,mid,x,dat);
		}else{
			update(p << 1 | 1,mid + 1,r,x,dat); 
		}
		tri[p] = tri[p << 1] + tri[p << 1 | 1];
	}
	Data query(int p,int l,int r,int ql,int qr){
		if(ql <= l and r <= qr){
			return tri[p];
		}
		int mid = (l + r) >> 1;
		if(qr <= mid){
			return query(p << 1,l,mid,ql,qr);
		}else if(ql > mid){
			return query(p << 1 | 1,mid + 1,r,ql,qr);
		}else{
			return query(p << 1,l,mid,ql,qr) + query(p << 1 | 1,mid + 1,r,ql,qr);
		}
	}
}
int c,T,n;
ll d,dat[N],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> T;
	while(T --){
		cin >> n >> d;
		for(int i = 1;i <= n;i ++){
			cin >> dat[i];
		}
		ans = 0;
		for(int i = 1;i <= n;i ++){
			SegmentTree::update(1,1,n,i,{0,1});
			for(int j = i + 1,k = i,lst = -1;j <= n;j ++){
				while(k < j and dat[k] < dat[j] - d){
					k ++;
				}
				if(k == j){
					break;
				}
				Data res = SegmentTree::query(1,1,n,k,j - 1);
				res.minn ++;
				ans += (res.cnt == 2);
				SegmentTree::update(1,1,n,j,res);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

