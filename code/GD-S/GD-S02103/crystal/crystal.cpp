#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long n,m,a[N],b[N];
int ans;
bool check(int x,int y){
	if(a[x]*(x-y)<=b[x-1]-b[y-1]+m) return 1;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) b[i] = b[i-1] + a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,tmp=0;
		while(l<=r){
			int mid = (l+r)/2;
			if(check(i,mid)){
				tmp = mid;
				r = mid-1;
			}else l = mid+1;
		}
		ans = max(ans,i-tmp+1);
	}
	cout << ans;
	return 0;
} 
