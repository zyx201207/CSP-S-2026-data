#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=-1;
	cin >> n >> m;
	long long a[500005];
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		long long x=m,cnt=0,l=i-1;
		if(i==1){
			l=1;
		}
		while(x>0&&l>=1){
			if(x>=a[i]-a[l]){
				x-=a[i]-a[l];
				l--;
				cnt++;
			}
			else break;
		}
		cnt+=1;
		ans=max(ans,cnt);
	}
	cout << ans;
	return 0;
}
//CSP2026S 2026-10-31 AFO 
//Li Ye love Zheng Shu Han
//Forever
