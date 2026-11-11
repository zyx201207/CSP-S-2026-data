#include<bits/stdc++.h>
using namespace std;
long long n,m,a[600000],cnt[600000],ans;
bool judge(long long l,long long r){
	if(a[r]*(r-l)-(cnt[r-1]-cnt[l-1])>m){
		return 0;
	}else{
		return 1;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		cnt[i]=a[i]+cnt[i-1]; 
	}
	for(long long i=1;i<=n;i++){
		long long l=i,r=n;
		while(l+1<r){
			long long mid=(l+r)>>1;
			if(judge(i,mid)){
				l=mid;
			}else{
				r=mid;
			}
		}
		ans=max(ans,l-i+1);
	}
	cout<<ans;
	return 0;
} 
