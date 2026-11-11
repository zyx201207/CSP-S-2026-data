#include <bits/stdc++.h>
using namespace std;
long long a[510000],b[510000];long long n,m;
int find(int i,int l,int r){
	int mid=(l+r)/2;
	if(l>=r)return l;
	if((i-mid+1)*a[i]>m+b[i]-b[mid-1]){
		return find(i,mid+1,r);
	}else{
		return find(i,1,mid);
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	long long st=1,ans=1;
	for(int i=2;i<=n;i++){
		if((i-st+1)*a[i]>m+b[i]-b[st-1]){
			st=find(i,st,i);
		}
		ans=max(ans,i-st+1);
	}
	cout<<ans;
	return 0;
}
