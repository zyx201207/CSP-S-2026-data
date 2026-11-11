#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],maxn=-1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;++i){
		int sum=1,sy=m;
		for(int j=i-1;j>=1;--j){
			if(a[i]-a[j]<=sy){
				sum++;
				sy-=a[i]-a[j];
			}
			else break;
		}
		if(a[i+1]==a[i]){
			int cf=0,next=i+1;
			for(int j=i+1;;++j){
				if(a[j]==a[i]){
					cf++;
					next=j+1;
				}
				else if(j>n)break;
				else break;
			}
			sum+=cf;
			i=next;
		}
		maxn=max(maxn,sum);
	}
	cout<<maxn;
	return 0;
}
