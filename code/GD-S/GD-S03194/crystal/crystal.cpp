#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=6e5+9;
int n,m,a[N];
int maxx=0,sum[N]; 
bool check(int x,int y){
	int p=sum[x]-sum[y-1];
	if(m>=a[x]*(x-y+1)-p)return 1;
	else return 0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	sum[0]=0;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		if(m>=(a[i]*i-sum[i]))maxx=max(maxx,i);
		else{
			int l=1,r=i;
			while(l<r){
				int mid=(l+r)>>1;
				if(check(i,mid))r=mid;
				else l=mid+1;
			}
			maxx=max(maxx,i-l+1); 
		}
	}
	cout<<maxx;
	return 0;
} 
