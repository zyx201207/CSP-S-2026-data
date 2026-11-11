#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 500005
int n,m;
int num[N],pre[N];
int ans=0;
bool cmp(int a,int b){
	return a<b;
}
bool check_ans(int u){
	for(int i=u;i<=n;i++){
		if((u*num[i]-(pre[i]-pre[i-u]))<=m){
			return 1;
		}
	}
	return 0;
}
void find_ans(){
	int l=1,r=n,mid,temp=0;
	while(l<r){
		if(temp>20){
			break;
		}
		mid=(l+r)/2;
		if(check_ans(mid)){
			l=mid;
		}
		else{
			r=mid-1;
		}
		temp++;
	}
	ans=l;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	pre[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&num[i]);
	}
	sort(num+1,num+n+1,cmp);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+num[i];
	}
	find_ans();
	printf("%lld",ans);
	
	
	return 0;
} 
