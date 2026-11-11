#include<bits/stdc++.h>
using namespace std;
long long n,m,sumw[31],ans,ak;
struct nd{
	long long mask,wei;
}a[255555];
bool cmp(nd d1,nd d2){
	return d1.mask>d2.mask;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	ak=m;
	for(int i=1;i<=n;i++){
		cin>>a[i].mask;
		long long num=a[i].mask;
		while(num){
			a[i].wei++;
			num>>=1;
		}
		sumw[a[i].wei]++;
	}
	int t=30;
	for(;t>=0;t--){
		if(sumw[t]>=m)break;
		m-=sumw[t];
	}
	for(int i=1;i<=n;i++){
		if(a[i].wei>t){
			long long u=0,o=0;
			while(o<t){
				o++;
				u+=((a[i].mask&1)<<(o-1));
				a[i].mask>>=1;
			}
			a[i].mask=u;
		}
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1].mask;
	for(int i=2;i<=ak;i++){
		ans&=a[i].mask;
	}
	cout<<ans;
	return 0;
}
