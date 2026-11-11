#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500005],b[500005],ans=1,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	for(int i=2;i<=n;i++){
		long long tmp=1;
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r)/2;
			if((i-mid)*a[i]-b[i-1]+b[mid-1]<=m){
				tmp=max(tmp,i-mid+1ll);
				ans=max(ans,i-mid+1ll);
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
//		cout<<"x="<<a[i]<<" "<<tmp<<endl;
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

*/ 
