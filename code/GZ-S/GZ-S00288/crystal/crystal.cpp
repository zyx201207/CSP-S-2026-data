//GZ-S00288 贵阳市南明区华麟学校 徐文景 
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10,M=1e9;
int n,m,ans;
int a[N],qzh[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i]; 
	sort(a+1,a+1+n);
	if(m>M) {
		bool f1=1,f2=1;
		int cmp=a[2]-a[1];
		for(int i=1;i<=n;i++){
			if(a[i]!=i){
				f1=0;
				break;
			}
		}
		for(int i=1;i<=n;i++){
			if(i>2&&a[i]-a[i-1]!=cmp){
				f2=0;
				break;
			}
		}
		//特判A
		if(f1){
			for(int i=1;i<=n-1;i++){
				if(m-i<0){
					cout << i+1;
					return 0;
				} else {
					m-=i;
				}
			}
		} else if(!f1&&f2){ //特判B 
			int cnt=m/cmp;
			for(int i=1;i<=n-1;i++){
				if(m-i*cnt<0){
					cout << i+1;
					return 0;
				} else {
					m-=i*cnt;
				}
			}
		}
	}
	for(int i=1;i<=n;i++) qzh[i]=qzh[i-1]+a[i];
	for(int r=n;r>1;r--){
		for(int l=1;l<r;l++){
			if(r-l+1<=ans) break;
			if(qzh[r-1]-qzh[l-1]+m>=a[r]*(r-l)){
				ans=max(ans,r-l+1);
				break;
			}
		}
	}
	cout << ans;
	return 0;
} 
