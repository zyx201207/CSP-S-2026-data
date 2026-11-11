#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e6+40;
int a[N];int n,m;
int cha[N],aa[N];
bool check(int mid){
	int num=0;
	for(int i=1;i<=n;i++){
		if(a[i]>mid)break;
		num+=(mid-a[i]);
	}
	return num<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		aa[i]=a[i]+aa[i-1];
		//cout<<aa[i]<<" ";
	}
	//cout<<'\n';
	int l=0,r=a[n]+1;
	while(l+1<r){
		int mid=l+r>>1;
		if(check(mid))l=mid;
		else r=mid;
	}
	//cout<<l;
	int zuida=l;
	int cha=0;
	int cnt=0;	
	for(int i=1;i<=n;i++){
		if(a[i]<=l){
			cnt++;
			//zzz+=a[i];
		}else {
			//jl=i;
			break;
		}
	}
	int ans=cnt;
	for(int j=cnt+1;j<=n;j++){
		for(int i=1;i<=cnt;i++){
			if((j-i)*a[j]-aa[j]<i*cnt-aa[i]){
					//cout<<1<<" ";
					//cout<<j<<" "<<i<<'\n';
					ans=max(j-i,ans);
				}
			}
	}
	cout<<ans;
	return 0;
} /*5 8
-3 -1 2 2 7
*/
