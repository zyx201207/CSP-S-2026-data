#include<bits/stdc++.h>
using namespace std;
long long n,m,a[50010],ans=0,pre[50010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==0){
		int ans=0,sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i-1]){
				ans=max(ans,sum);
				sum=0;
			}
			sum++;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(pre,0,sizeof(pre));
		for(int j=1;j<=i;j++){
			pre[j]=abs(a[i]-a[j]);
		}
		sort(pre+1,pre+n+1);
		int sum=0,k=0;
		for(int j=1;j<=i;j++){
			if(sum+pre[j]<=m){
				sum+=pre[j];
				k++;
			}else break;
		}
		ans=max(ans,1ll*k);
	}
	cout<<ans;
	return 0;
}
