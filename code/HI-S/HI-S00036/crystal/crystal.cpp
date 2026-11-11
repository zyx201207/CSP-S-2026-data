#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500100];
int ans;
long long d[500100];
int check(int c,int w){
	int k=a[w]*(w-c)-(d[w]-d[c-1]);
	return k<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) d[i]=a[i]+d[i-1];	
	for(int i=2;i<=n;i++){
		int l=0,r=i,sum=0;
		while(l<r){
			int mid=l+(r-l)/2;
			if(check(mid,i)){
				sum=i-mid;
				r=mid-1;
				
			}
			else l=mid+1;
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}



