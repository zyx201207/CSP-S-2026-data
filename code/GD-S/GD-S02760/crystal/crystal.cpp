#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans=1;
map<int,int> p;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		p[a[i]]++;
	}sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		int sum=1,num=m;
		for(int j=i-1;j>0;--j){
			if(num>=a[i]-a[j]){
				num-=a[i]-a[j];
				sum++;
			}else break;
		}ans=max(sum,ans);
	}cout<<ans;
	return 0;
}
//ÄÃ¸ö45²»´íÁË¡£ 
