#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,ans;
long long m,a[N],tmp,sum[N];
bool check(int x,int id){
	long long res;
	res=(x*a[id]-sum[x]);
	return (tmp-res)<=m;
} 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		tmp+=(i-1)*(a[i]-a[i-1]);
		int l=0,r=i;
		while(r-l>1){
			int mid=(l+r)>>1;
			if(check(mid,i)){
				r=mid;
			}
			else{
				l=mid+1;
			}
		}
		ans=max(ans,i-l);
	}
	cout<<ans;
	return 0;
} 
