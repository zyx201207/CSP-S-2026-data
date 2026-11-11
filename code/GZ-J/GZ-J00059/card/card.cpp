//黄烨 GZ-J00059 毕节七星关东辰实验学校 
#include<iostream>
#define ll long long
using namespace std;
ll n,m;
ll fin[50010];
ll ans[50010];
ll a[50010];
ll sum[50010];
bool flag[50010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum[i]=a[i];
		if(fin[a[i]]==0){
			fin[a[i]]=i;
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll s=1;s<=n;s++){
			sum[s]=0;
			flag[s]=false;
		}
		for(ll j=1;j<=n;j++){
			sum[j]=a[j+i-1];
			flag[sum[j]]=true;
			if(fin[sum[j]]<j && flag[sum[j]]){
				for(ll k=fin[sum[j]];k<j;k++){
					sum[k]=0;
				}
				sum[fin[sum[j]]]=sum[j];
			}
		}
		for(ll j=i;j<=n;j++){
			if(sum[j]!=0)
			ans[sum[j]]+=1;
		}
	}
	for(ll i=1;i<=m;i++){
		printf("%lld ",ans[i]);
	}
	return 0;
}
