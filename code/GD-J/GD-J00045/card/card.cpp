#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],ans[N],b[N],lst[N],c[N],sum[N],anss[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		ans[i]=i;
	}
	for(long long i=1;i<=n;i++){
		if(lst[a[i]]!=0){
			b[lst[a[i]]]+=lst[a[i]];
			c[i]=lst[a[i]];
		}
		lst[a[i]]=i;
	}
	for(long long i=1,sum=0,lstsum=0;i<=n;i++){
		if(c[i]>0){
			sum-=ans[c[i]];
		}
		lstsum=sum;
		if(b[i]>0)sum=sum+b[i]-sum;
		ans[i]=sum-lstsum;
		anss[a[i]]=max(anss[a[i]],i-sum);
	}
	for(long long i=1;i<=m;i++)cout<<anss[i]<<" ";
	return 0;
}
