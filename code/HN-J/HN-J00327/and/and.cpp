#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

namespace solution{
	int n,m;
	int a[200005];
	bool available[200005];
//	int siz;
//	int sum[6000005];
//	void pushup(int id){
//		sum[id] = sum[id*2]+sum[id*2+1];
//	}
//	void fix(int id,int L,int R,int pos){
//		if(L==R){
//			sum[id]++;
//			return ;
//		}
//		int mid = (L+R)>>1;
//		if(pos<=mid) fix(id*2,L,mid,pos);
//		else fix(id*2+1,mid+1,R,pos);
//		pushup(id);
//	}
//	int ans;
//	void query(int id,int L,int R,int val){
//		if(L==R){
//			
//		}
//	}
	void main(){
		cin>>n>>m;
		for(int i = 1;i<=n;i++) cin>>a[i],available[i] = true;
		int bit = 30;
		int ans = 0;
		while(~bit){
			int cnt = 0;
			for(int i = 1;i<=n;i++){
				if(available[i]&&(a[i]&(1ll<<bit))){
					cnt++;
				}
			}
			if(cnt>=m){
				ans|=(1ll<<bit);
				for(int i = 1;i<=n;i++){
					if((a[i]&(1ll<<bit))){
						available[i]&=true;
					}else available[i]&=false;
				}
			}
			bit--;
		}
		cout<<ans;
	}
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	solution::main();
	return 0;
}

