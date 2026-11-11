#include<bits/stdc++.h>//100pts
using namespace std;
#define int long long
const int N=5e5+111;
int a[N];
int t[N];
int n,m;
bool check(int l,int r){
	return (r-l+1)*a[r]-(t[r]-t[l-1])<=m;
}
#undef int
int main(){
	#define int long long
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		t[i]=t[i-1]+a[i];
	}
	int maxx=1;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		int ans=0;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid,i)){
				ans=mid;
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		maxx=max(maxx,i-ans+1);
	}
	printf("%d",maxx);
	return 0;
} 
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

I love Yore_Snow!!!!!!

Only feels like nothing could be better when I with you,when I with you~
*/
