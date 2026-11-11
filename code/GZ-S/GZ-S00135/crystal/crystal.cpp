//GZ-S00135 胡睿晨 北京师范大学贵阳附属中学
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ma=-0x3f3f3f,mi=1<<40,sum,cnt,tmp;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
		mi=min(mi,a[i]);
	}
	sort(a+1,a+n+1);
	for (int i=ma-m,j=ma;j>=1;i--,j--){
		for (int k=n;a[k]>=i && k>0;k--){
			if (a[k]<=j){
				tmp+=j-a[k];
				if (tmp>m) break;
				cnt++;
			}
		}
		sum=max(sum,cnt);
		cnt=0,tmp=0;
	}
	cout<<sum;
	return 0;
}
