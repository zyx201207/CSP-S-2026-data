#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int N=5*1e5+5;
int n,m,a[N],maxn=1; 
int cmp(int x,int y){
	return x<y;
}
int check(int x){
	int usem=m,ans=1;
	for(int i=x-1;i>=1;i--){
		int w=a[x]-a[i];
		if(usem-w>=0){
			usem-=w;
			ans++;
		}else{
			break;
		}
	}
	return ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)/2;
		if(check(mid)>maxn){
			maxn=check(mid);
			l=mid+1;
		}else{
			r=mid;
		}
	}
	cout<<maxn;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

*/
