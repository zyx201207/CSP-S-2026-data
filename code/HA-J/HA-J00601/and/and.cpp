#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0,maxi=0;
const int N=2e5+5;
int a[N];
namespace task1to5{
	int pct(int x){
		int cnt=0;
		while (x){
			x&=x-1;
			cnt++;
		}
		return cnt;
	}
	void solve(){
		for (int i=0;i<(1<<n);i++){
			if (pct(i)!=m) continue;
			int res=(1<<20)-1;
			for (int j=1;j<=n;j++) if ((i>>(j-1))&1) res&=a[j];
			ans=max(ans,res);
		}
		cout<<ans<<endl;
	}
}
namespace task6{
	void solve(){
		for (int i=1;i<=n;i++) ans=max(ans,a[i]);
		cout<<ans<<endl;
	}
}
namespace task7{
	void solve(){
		ans=(1<<20)-1;
		for (int i=1;i<=n;i++) ans&=a[i];
		cout<<ans<<endl;
	}
}
namespace task8to10{
	void solve(){
		for (int i=1;i<=n;i++) for (int j=i+1;j<=n;j++) ans=max(ans,a[i]&a[j]);
		cout<<ans<<endl;
	}
}
namespace task16to17{
	void solve(){
		int cnt[4]={0,0,0,0};
		for (int i=1;i<=n;i++) cnt[a[i]]++;
		if (cnt[3]>=m) cout<<3;
		else if (cnt[2]+cnt[3]>=m) cout<<2;
		else if (cnt[1]+cnt[3]>=m) cout<<1;
		else cout<<0;
		cout<<endl;
	}
}
namespace taskall{
	bool check(int x){
		int res=0;
		for (int i=1;i<=n;i++) if ((a[i]&x)==x) res++;
		return res>=m;
	}
	void solve(){
		int l=0,r=(1<<30)-1;
		while (l<r){
			int mid=(l+r+1)/2;
			if (check(mid)){
				l=mid;
			} else {
				r=mid-1;
			}
		}
		cout<<r<<endl;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		maxi=max(maxi,a[i]);
	}
	if (n<=20) task1to5::solve();
	else if (m==1) task6::solve();
	else if (m==n) task7::solve();
	else if (n<=2000&&m==2) task8to10::solve();
	else if (maxi<4) task16to17::solve();
	else taskall::solve();
	return 0;
}
