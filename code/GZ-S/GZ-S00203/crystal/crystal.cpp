//GZ-S00203 北京师范大学贵阳附属中学 周一宸  
#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+20;

int n;
long long m;
long long a[N];
long long he[N];
int lans,ans = 0;
int l,r,mid;

bool cheek(int z,int i){
	return (i-z)*a[i]-(he[i-1]-he[z-1])<=m;
}

int main () {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i =1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i =1;i<=n;i++){
		he[i] = he[i-1]+a[i];
		lans = 0;
		l =1,r = i,mid = (l+r)>>1;
		while(l<r){
			mid = (l+r)>>1;
			if(cheek(mid,i)){
				r = mid;
			}
			else l = mid+1;
		}
		lans = i-r+1;
		ans = max(ans,lans);
	}
	cout<<ans;
	return 0 ;
}

