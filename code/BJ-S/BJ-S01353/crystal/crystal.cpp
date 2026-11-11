#include<bits/stdc++.h>
using namespace std;
#define int LL
typedef long long LL;
const int N=500010;
int n,m,ans;
int a[N];
int mx=-1*0x3f3f3f3f3f3f3f3f,mi=0x3f3f3f3f3f3f3f3f;
int check(int x){
	int num=0;
	for(int i=1;i<=n;i++){
		if(a[i]>=x){
			break;
		}
		num+=(x-a[i]);
	}
	return num;
}
signed main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		mi=min(mi,a[i]);
	}
	sort(a+1,a+1+n);
	if(n>5000){
		int l=mi,r=mx,mid;
		while(l<=r){
			mid=(l+r)/2;
			if(check(mid)<=m){
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		//结果为将水晶变为r
		for(int i=1;i<=n;i++){
			if(a[i]<=r){
				ans++;
			}
		}
		cout<<ans<<"\n";
	}else{
		for(int i=1;i<=n;i++){
			int w=0,num=0;
			for(int j=i;j>=1;j--){
				w+=a[i]-a[j];
				if(w<=m){
					num++;
				}else{
					break;
				}
			}
			ans=max(ans,num);
		}
		cout<<ans<<"\n";
	}
	return 0;
}