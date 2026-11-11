#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxn=-1,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) ans=a[i];
		else ans=ans&a[i];
		if(a[i]>=maxn) maxn=a[i];
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	if(m==n){
		cout<<ans;
		return 0;
	}
	if(m==2){
		maxn=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i]&a[j]>maxn) maxn=a[i]&a[j];
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==n-1){
		ans=0,maxn=-1;
		for(int i=1;i<=n;i++){
			if(i==1) ans=a[2];
			else ans=a[1];
			for(int j=1;j<=n;j++){
				if(i!=j) ans=ans&a[j];
			}
//			cout<<ans<<' ';
			maxn=max(maxn,ans);
		}
		cout<<maxn;
		return 0;
	}
	else{
		cout<<0;
		return 0;
	}
	return 0;
} 
