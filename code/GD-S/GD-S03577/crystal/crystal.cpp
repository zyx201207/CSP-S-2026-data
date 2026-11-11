#include<bits/stdc++.h>
using namespace  std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,cnt=0,sum=1;
	cin>>n>>m;
	int a[n+1],v[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int l,r;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		l=a[1];
		r=a[n];
	}
	int mid=(l+r)/2;
	for(int i=1;i<=n;i++){
		v[i]=abs(a[i]-mid);
		sort(v+1,v+n+1);
		if(cnt+v[i]<=m){
			cnt+=v[i];
			sum++;
		}else{
			cout<<sum;
			return 0;
		}
	}
	return 0;
}
