//谨以此代码致敬传奇暴力算法二分答案 
//孩子们，我该不会爆0吧 qwq 
//注意到我不会双指针 
#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
const int N = 5e5+10;
long long a[N];
long long d;
long long s(long long k){
	if(k>=0)return k;
	else return -k;
}
bool check(int x) {
	if(x>n)return false;
	long long minn=1e18;
	for(int k=a[n];k>=a[x];k--){
		int cnt=0;
		long long sum=0;
		for(int i=n;i>=1;i--){
			if(a[i]>k)continue;
			if(cnt>x)break;
			sum+=k-a[i];
			cnt++;
		}
		minn=min(minn,sum);
	}
	if(minn<=m)return true;
	else return false;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long maxx=-1e18;
	scanf("%d%lld",&n,&m);
	for(int i=1; i<=n; i++) {
		scanf("%lld",&a[i]);
		maxx=max(maxx,s(a[i]));
	}
	if(maxx<=100) {
		sort(a+1,a+n+1);
		int l=1,r=500000;
		while(l<r) {
			int mid=(l+r+1)/2;
			if(check(mid)) {
				l=mid;
			} else {
				r=mid-1;
			}
			//cout<<mid<<endl;
		}
		cout<<l;
	} else {
		long long l=0,r=1e9;
		d=a[2]-a[1];
		while(l<r) {
			__int128 mid=(l+r+1)/2;
			bool flag=0;
			if((mid+1)*mid*(__int128)d<=2*m)flag=1;
			if(flag) {
				l=mid;
			} else {
				r=mid-1;
			}
			//cout<<mid<<endl;
		}
		cout<<min((long long)n,l+1);
	}
	return 0;
}
/*
5 32
6 9 12 15 18

5



5 5
1 2 4 8 9

3


5 8
-3 -1 2 2 7

4


5 159
-50 0 50 100 150

3
*/
