//GZ-S00373 贵阳市华师一学校 蒋金珂 
#include<bits/stdc++.h>
using namespace std;
long long a[500001],n,m,b[500001];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i]; 
	}int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)/2;
			if(a[i]*(i-mid+1)-(b[i]-b[mid-1])<=m){
				r=mid;
			}else{
				l=mid+1;
			}
		}ans=max(ans,i-l+1);
		
	}cout<<ans;
}

