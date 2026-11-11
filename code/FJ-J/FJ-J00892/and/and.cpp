#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200010];
//部分
//m=1 选最大
//全选……
void solve6(){
	long long ans=-1;
	for(int i=1;i<=n;i++){
		ans=max(ans,a[i]);
	}
	cout<<ans;
	return;
}
void solve7(){
	long long ans=a[1];
	for(int i=2;i<=n;i++){
		ans=ans&a[i];
	}
	cout<<ans;
}
void solve8_10(){
	long long ans=-1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			ans=max(ans,a[i]&a[j]);
		}
	}
	cout<<ans;
}
long long ans15;
int ii;
//
void solve1_5(long long step,long long maxn,long long ans){
//	cout<<step<<" "<<ans<<" "<<maxn<<endl;
	if(step==0){
		
		return;
	}
	ans15=max(ans,ans15);
	for(int i=1;i<maxn;i++){
		//	cout<<"do"<<endl;
		solve1_5(step-1,i,ans&a[i]);
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(m==1){
		solve6();
	}else if(m==n){
		solve7();
	}else if(m==2){
		solve8_10();
	}else{
		for(ii=1;ii<=n;ii++) {
			//for(int i=1;i<=n;i++){
				solve1_5(m,ii,a[ii]);
			//}
			
		}
			
		cout<<ans15;
	}
	return 0;
}
//