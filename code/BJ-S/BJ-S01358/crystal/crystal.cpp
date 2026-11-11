#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
long long m,a[N],b[N],ans;

void Solve(int l,int r){
	if(l==r) return ;
	int mid=(l+r)/2;
	Solve(l,mid);
	Solve(mid+1,r);
	int p=l,q=mid+1,x=l;
	while(p<=mid && q<=r){
		if(a[p]<a[q]){
			b[x++]=a[p++];
		}else{
			b[x++]=a[q++];
		}
	}
	while(p<=mid) b[x++]=a[p++];
	while(q<=r) b[x++]=a[q++];
	for(int i=l;i<=r;i++){
		a[i]=b[i];
	}
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//sort(a+1,a+n+1);
	Solve(1,n);
	long long sum=0,l=1,r=1;
	while(r<=n){ //[l,r]
		while(sum<=m && r<=n){
			r++;
			sum+=(a[r]-a[r-1])*(r-l);
		}
		ans=max(ans,r-l);
		sum-=a[r]-a[l];
		l++;
	}
	cout<<ans;
	return 0;
}
