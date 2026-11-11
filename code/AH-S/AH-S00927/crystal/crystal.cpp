#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,a[N],q[N],ans,m,sum=1;
void finds(int x){
	x-=1;
	int l=1,r=x,mid=0;
	while(l<=r){
		mid=(l+r)/2;
		if(abs((a[x+1]*(x-mid+1)-(q[x]-q[mid-1])))<=m){
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	if(abs((a[x+1]*(x-mid+1)-(q[x]-q[mid-1])))<=m){
		ans=max(ans,sum+(x-mid+1));
	}
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
		q[i]=q[i-1]+a[i];
	}
	for(int i=1,j;i<=n;i=j+1,sum=1){
		for(j=i;a[j]==a[j+1]&&j<n;j++,sum++);
		finds(i);
	}
	cout<<ans;
	return 0;
}
