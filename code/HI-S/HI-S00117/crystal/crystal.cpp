#include<bits/stdc++.h>
using namespace std;
long long m,m1,ans=0,cnt,sum=0;
int n;
long long a[500005];
map <long long, int > mp;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		mp[a[i]]++;
	}
	sort(a+1,a+n+1);
	int mid=(1+n)/2;
	
	int l=1,r=n;
	while(l<r){
		mid=(l+r)/2;
		m1=m,cnt=mp[a[mid]];
		for(int i=mid-1;i>=1;i--){
		if(m1>=(a[mid]-a[i])){
			m1-=(a[mid]-a[i]);
			cnt++;
		}
		else{	
			break;
		}
	}	
		if(ans<cnt){
			l=mid+1;
		}
		else {
			r=mid-1;	
		}
		ans=max(ans,cnt);
	}
	bool p=1;
	while(l<r){
		mid=(l+r)/2;
		m1=m,cnt=mp[a[mid]];
		for(int i=mid-1;i>=1;i--){
		if(m1>=(a[mid]-a[i])){
			m1-=(a[mid]-a[i]);
			cnt++;
		}
		else{	
			break;
		}
	}	if(p){
		r=mid-1;
		p=0;
	}
		else if(sum<cnt){
			l=mid+1;
		}
		else {
			r=mid-1;	
		}
		sum=max(sum,cnt);
	}
	printf("%lld",max(sum,ans));
	return 0;
}
