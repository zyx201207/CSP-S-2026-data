#include<bits/stdc++.h>
using namespace std;
struct node{
	long long l,r,len;
	char x;
}a[500005],b[500005];
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].len>>a[i].x;
		a[i].l=a[i-1].r+1,a[i].r=a[i-1].r+a[i].len;
	}
	for(int i=1;i<=n;i++) b[i]={b[i-1].r+1,b[i-1].r+a[n-i+1].len,a[n-i+1].len,a[n-i+1].x};
//	for(int i=1;i<=n;i++) cout<<a[i].l<<' '<<a[i].r<<' '<<b[i].l<<" "<<b[i].r<<'\n';
	int l=1,r=1;
	long long ans=0;
	while(l<=n&&r<=n){
		if(a[l].x==b[r].x){
			if(a[l].r<b[r].r) l++;
			else if(a[l].r>b[r].r) r++;
			else l++,r++;
		}
		else{
			ans+=min(a[l].r,b[r].r)-max(a[l].l,b[r].l)+1;
			if(a[l].r<b[r].r) l++;
			else if(a[l].r>b[r].r) r++;
			else l++,r++;
		}
	}
	cout<<ans/2;
	return 0;
}

