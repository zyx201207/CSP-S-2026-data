#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5000010],d[5000010],zui;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1]&&i>1&&a[i+1]==a[i])continue;
		long long p=0;
		for(int j=i-1;j>=1;j--){
			d[j]=a[i]-a[j];
			p+=d[j];
		}
		if(p<=m){
			long long ans=0;
			for(int j=1;j<=n;j++)
				if(a[j]<=a[i])ans++;
			if(ans<zui)break;
			zui=max(zui,ans);
			continue;
		}
		long long sum=0;
		for(int j=i-1;j>=1;j--){
			if(d[j]<m){
				m-=d[j];a[j]=a[i];sum++;
			}else break;
		}
		for(int j=i;j<=n;j++)
			if(a[j]==a[i])sum++;
		if(sum<zui)break;
		zui=max(zui,sum);
	}
	cout<<zui;
	return 0;
}
