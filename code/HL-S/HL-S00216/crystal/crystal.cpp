#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
long long a[N],n,k,sum[N],ans=1;
long long gets(int l,int r){
	return sum[l]-sum[r-1];
}
bool check(int pos,int dx){
	if(a[pos]*(pos-dx+1)-gets(pos,dx)<=k) return 1;
	else return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		long long res=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(i,mid)){
				res=mid;
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans;
	return 0;
}
