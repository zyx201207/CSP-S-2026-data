#include<bits/stdc++.h>
using namespace std;
const int N=5e5+2;
int n,m,cnt[N],mx;
long long a[N],t[N],sum;
void msort(int l,int r){
	if(l==r)return;int mid=l+r>>1;msort(l,mid),msort(mid+1,r);
	int i=l,j=mid+1,x=l;
	while(i<=mid&&j<=r)
		if(a[i]<a[j])t[x++]=a[i++];
		else t[x++]=a[j++];
	while(i<=mid)t[x++]=a[i++];
	while(j<=r)t[x++]=a[j++];
	for(i=l;i<=r;i++)a[i]=t[i];
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m,a[n+1]=1e13;
	for(int i=1;i<=n;i++)cin>>a[i];
	msort(1,n);
	for(int i=n;i;i--)cnt[i]=cnt[i+1]*(a[i]==a[i+1])+1;
	for(int i=1,hd=1;i<=n;sum+=a[i],i++,hd++)
		if((hd-1)*a[i]-sum<=m)mx=max(mx,hd+cnt[i]-1);
		else{
			while(hd&&(hd-1)*a[i]-sum>m)sum-=a[i-hd+1],hd--;
			mx=max(mx,hd+cnt[i]-1);
		}
	cout<<mx;
	return 0; 
}
