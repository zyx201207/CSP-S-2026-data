#include<bits/stdc++.h>
#define map unordered_map
using namespace std;
const int N=2e5+5;
int n,m,ans,an,x;
struct doge{
	int num,cnt;
}f[N];
bool cmp(doge x,doge y){
	if(x.num!=y.num) return x.num>y.num;
	return x.cnt>y.cnt;
}
bool bmp(doge x,doge y){
	if(x.cnt!=y.cnt) return x.cnt>y.cnt;
	return x.num>y.num;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		f[i].num=x;
		while(x){
			f[i].cnt+=x%2;
			x/=2;
		}
	}
	sort(f+1,f+n+1,cmp);
	ans=f[1].num;
	for(int i=2;i<=m;i++){
		ans=ans&f[i].num;
	}
	sort(f+1,f+n+1,bmp);
	an=f[1].num;
	for(int i=2;i<=m;i++){
		an=an&f[i].num;
	}
	cout<<max(ans,an);
	return 0;
} 
