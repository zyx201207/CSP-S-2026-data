#include<bits/stdc++.h>
using namespace std;
bool flag=true;
long long ans,cnt,o,p,n,m,a[500010],f[500010];
void u(int q){
	p=m,o=1,cnt=0;
	for(int i=q;i<n;i++){
		if(n-i+1+cnt<ans)return ;
		if(p>=f[i]*o){
			p-=f[i]*o;
			o++;
			cnt++;
			ans=max(ans,cnt);
		}else{
			o=1;
			cnt=0;
			p=m;
			if(p>=f[i]*o){
				p-=f[i]*o;
				o++;
				cnt++;
				ans=max(ans,cnt);
			}
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)f[i]=a[i+1]-a[i];
	for(int i=1;i<n;i++)if(f[i]!=f[i+1]&&i+1<n)flag=false;
	if(flag){
		for(int k=1;k<=n;k++){
			if((k+1)*k/2*f[1]>m){
				cout<<k-1;
				return 0;
			}
		}
		cout<<m;
		return 0;
	}
	for(int j=1;j<=n;j++)u(j);
	cout<<ans+1;
	return 0;
}
