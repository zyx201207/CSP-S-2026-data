//GZ-S00075 唐文博
#include<bits/stdc++.h>
using namespace std;
const long long N=50010;
long long n,m,a[N],maxn=INT_MAX,k;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a,a+n);
	for(int i=n;i>1;i--){
		long long cha=0;
		for(int j=1;j<i;j++) cha+=a[i]-a[j];
		if(abs(maxn-m)>abs(cha-m)){
			maxn=min(maxn,cha);
			k=i;
		}
	}
	cout<<k;
}
