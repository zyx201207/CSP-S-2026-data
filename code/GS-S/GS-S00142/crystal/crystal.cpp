#include<bits/stdc++.h>
using namespace std;
int n;
unsigned long long m,ans,m2,cnt;
long long a[500010],q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m2;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		q=a[i];
		m=m2;
		for(int j=i;j>=1;--j){
			if(a[j]<=q&&(q-a[j])<=m){
				m=m-(q-a[j]);
				++cnt;
			}
		}
		ans=max(ans,cnt);
		cnt=0;
	}
	cout<<ans;
	return 0;
}
