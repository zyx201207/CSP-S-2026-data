#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxn=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1){
	   cout<<maxn;
	   return 0;
    }
    if(m%2==1){
		sort(a+1,a+n+1);
		cout<<a[n+1-m];
	}
    if(m==2){
		int maxnn=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				maxnn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxnn;
	}
    if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++)ans&=a[i];
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		int maxn=-1;
		for(int i=1;i<=n;i++){
		    int ans;
		    if(i!=1)ans=a[1];
		    else ans=a[2];
		    for(int j=1;j<=n;j++){
			    if(j==i)continue;
			    ans&=a[j];
			}
			maxn=max(maxn,ans);
		}
		cout<<maxn;
	}
}
