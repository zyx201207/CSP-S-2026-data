#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5,Maa=1e12+1;
long long a[N];
int ans,n;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long m;
	cin>>n>>m;
	long long Mi=Maa,Ma=-Maa;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		Ma=max(a[i],Ma);
		Mi=min(Mi,a[i]);
	}
	int l=Mi,r=Ma;
	sort(a+1,a+n+1);
	while(l<=r){
		long long mid=(l+r)/2;
		long long sum=-999,sd;
		auto b=a;
		for(int i=1;i<=n;i++){
			sd=sum;
			sum=max(sum,sum+mid-b[i]);
			if(sum!=sd)b[i]=mid;
		}
		if(l>m){
			r=mid-1;
		}
		else {
			int t[Maa];
			for(int i=1;i<=n;i++){
				ans=max(ans,++t[b[i]]);
			}
			l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}
//不知道为什么爆3221225725  谁能帮我看 又没有报错又啥都不输出 
//Process exited after 1.428 seconds with return value 3221225725
