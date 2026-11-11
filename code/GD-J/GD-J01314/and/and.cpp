#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
long long ma,mx;
long long p[35];
bool f=0;
void dfs(int step,int x,long long ans){
	if(step>m){
		ma=max(ma,ans);
		return;
	}
	for(int i=x+1;i<=n;i++){
		if(step==1) dfs(step+1,i,a[i]);
		else dfs(step+1,i,ans&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	p[1]=1;
	for(int i=2;i<=25;i++) p[i]=p[i-1]*2;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		bool ok=0;
		if(a[i]==1) ok=1;
		else{
			for(int j=2;j<=20;j++){
				if(a[i]==p[j]-1){
					ok=1;
					break;
				}
			}
		}
		if(!ok) f=1;
		mx=max(mx,a[i]);
	}
	if(m==1){
		long long maa=0;
		for(int i=1;i<=n;i++) maa=max(maa,a[i]);
		cout<<maa;
		return 0;
	}
	if(m==n){
		long long sum=a[1];
		for(int i=2;i<=n;i++) sum&=a[i];
		cout<<sum;
		return 0;
	}
	if(!f){
		sort(a+1,a+n+1);
		cout<<a[m];
		return 0;
	}
	dfs(1,0,0);
	cout<<ma;
	return 0;
}
