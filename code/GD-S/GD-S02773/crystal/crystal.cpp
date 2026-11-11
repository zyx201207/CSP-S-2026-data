#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m;
int a[N],ans,b[N];
bool check(int num){
	int cnt=0;
	for(int i=1;i<=n;i++){
		int sum=0;
		if(i-num+1<=0)continue;
		sum=a[i]*num-(b[i]-b[i-num]);
		if(sum<=m)return true;
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=a[i]+b[i-1];
	int l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
} 
/*

5 5
1 2 4 8 9



5 8
-3 -1 2 2 7


7 2
1 4 9 7 1 7 1 

*/
