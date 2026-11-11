#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,maxx;
int lst[N],f[N];
bool check(int k,int w){
	int p=f[w-1]-f[k-1];
	int q=(w-k)*lst[w];
	return q-p>=0&&(q-p)<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>lst[i];
	sort(lst+1,lst+1+n);
	for(int i=1;i<=n;i++)f[i]=lst[i]+f[i-1];
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=l+r>>1;
			if(check(mid,i))r=mid;
			else l=mid+1;
		}
		maxx=max(maxx,i-l+1);
	}
	cout<<maxx<<endl;
	return 0;
}
//zmh GD-S01968
