#include<bits/stdc++.h>
using namespace std;
struct node{
	long long l,r;
	char c;
}a[200010];
int n;
int mid(long long d){
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid].l<=d){
			ans=max(ans,mid);
			l=mid+1;
		}else r=mid-1;
	}
	return ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long t=0;
		cin>>t>>a[i].c;
		a[i].l=a[i-1].r+1;
		a[i].r=a[i].l+t-1;
	}
	long long ans=0; 
	for(int i=1;i<=n;i++){
		long long l=a[n].r-a[i].r+1,r=a[n].r-a[i].l+1;
		if(l<=a[i].l)break;
		int x=mid(l),y=mid(r);
		for(int j=x;j<=y;j++){
			if(a[j].c!=a[i].c)ans+=a[j].r-a[j].l+1;
		}
		if(a[x].c!=a[i].c)ans-=(l-a[x].l);
		if(a[y].c!=a[i].c)ans-=(a[y].r-r);
	}
	cout<<ans;
	return 0;
}
