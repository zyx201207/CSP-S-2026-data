#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
long long num[200005];
void DFS(int k,long long sum,int shu){
	if(shu==m){
		ans=max(ans,sum);
		return;
	}
	if(shu>m) return;
	for(int i=k;i<=n;i++){
		int su=sum;
		if(su==0) DFS(i+1,num[i],shu+1);
		else DFS(i+1,su&=num[i],shu+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>num[i];
	if(m==1&&n>20&&n<=2000){
		long long Max=INT_MIN;
		for(int i=1;i<=n;i++) Max=max(num[i],Max);
		cout<<Max;
		return 0;
	}
	if(m==n&&n>20&&n<=2000){
		ans=num[1];
		for(int i=2;i<=n;i++) ans&=num[i];
		cout<<ans;
		return 0;
	}
	if(m==2&&n>20&&n<=2000){
		long long res;
		for(int i=1;i<=n;i++){
			res=num[i];
			for(int j=i+1;j<=n;j++){
				res&=num[j];
				ans=max(res,ans);
				res=num[i];
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1&&n>2000){
		long long res=num[1];
		for(int i=2;i<=n;i++) res&=num[i];
		for(int i=1;i<=n;i++){
			res&=num[i];
			ans=max(res,ans);
			res&=num[i];
		}
		cout<<ans;
		return 0;
	}
	DFS(1,0,0);
	cout<<ans;
	return 0;
}
