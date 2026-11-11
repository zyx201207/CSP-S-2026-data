#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	int l=1,r=n;
	while(l<r){
		long long mid=(l+r)/2;
		bool fg=false;
		long long num=0;
		for(int i=1;i<=mid;i++){
			num+=a[mid]-a[i];
			if(num>m){
				fg=true;
				break;
			}
		}
		if(fg) r=mid;
		else{
			ans=max(ans,mid);
			l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}
