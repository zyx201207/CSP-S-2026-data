#include<bits/stdc++.h>
using namespace std;
long long op,mid,l,r,ke;
long long n,m,a[500006],ans=1e9,cnt,pot;
bool check(long long num){
	op=0;
	for(long long i=1;i<=mid;i++){
			op+=num-a[i];
	}
	if(op>ans)return 0;
	else return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	 l=1,r=n,mid=(l+r)/2;
	sort(a+1,a+n+1);
	while(l<=r){
		
		mid=(l+r)/2;
		if(check(a[mid])){
			l=mid+1;ke=mid;
			ans=min(ans,op);
		}else{
			r=mid-1;
		}
	}
	for(long long i=ke;i>=1&&m>0;i--){
		long long q=a[ke]-a[i];
		if(m>=q){
			m-=q;
			cnt++;
		}	
	}if(cnt==0){
		cout<<1;
		return 0;
	}
	cout<<cnt;
	return 0;
}
