#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500010;
int n;
ll m;
ll a[N];
ll c[N];
ll ans=1;
ll ac[N];
ll acc[N];
bool checkA=true;
bool checkB=true;
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=i){
			checkA=false;
		}
		if(i>2){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
				checkB=false;
			}
		}
	}
	if(checkA){
		for(int i=1;i<n;i++){
			ac[i]=ac[i-1]+a[i];
			if(m<ac[i]){
				printf("%d",i);
				return 0;
			}
		}
		printf("%d",n);
		return 0;
	}

	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		c[i]=a[i+1]-a[i];
		ac[i]=ac[i-1]+c[i];
	} 
	if(checkB){
		for(int i=1;i<n;i++){
			acc[i]=acc[i-1]+ac[i];
			if(m<acc[i]){
				printf("%d",i);
				return 0;
			}
		}
		printf("%d",n);
		return 0;
	}
	for(int i=n;i>=1;i--){
		ll sum=1;
		ll cnt=0;
		ll mn=m;
		for(int j=i-1;j>=1;j--){
			cnt+=c[j];
			if(cnt<=mn){
				sum++;
				mn-=cnt;
				//printf("%d ",j);
			}
			else{
				break;
			}
		}
		//printf("%d:%lld \n",i,sum);
		ans=max(ans,sum);
		if(ans>=i){
			break;
		}
	}
	printf("%lld",ans);
}
