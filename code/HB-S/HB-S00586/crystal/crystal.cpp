#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],cnt=0,ans=0,l=1,sum=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		ans++;
		cnt+=ans*(a[i]-a[i-1]);
		if(cnt>m){
			while(cnt>m){
				ans--;
				cnt-=a[i]-a[l];
				l++;
			}
		}
		sum=max(sum,ans);
	}
	cout<<sum+1<<'\n';
	return 0;
}
