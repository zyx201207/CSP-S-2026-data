#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m;
vector<int> a;
int pow2[35];
int xuan(vector<int> x,int wei) {
	if(x.size()<m) return 0;
	if(wei==-1) return 0;
	vector<int> sz;
	for(int i=wei;i>=0;i--) {
		sz.clear();
		int cnt=0;
		for(auto j:x) {
			if(j&pow2[i]) {
				cnt++;
				sz.push_back(j);
			}
		}
		if(cnt>=m && sz.size()>=m) {
			return pow2[i]+xuan(sz,i-1);
			break;
		}  
	}
	return 0;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		int x;
		cin>>x;
		a.push_back(x);
	}
	pow2[0]=1;
	for(int i=1;i<=34;i++) pow2[i]=pow2[i-1]*2;
	cout<<xuan(a,32); 
}
