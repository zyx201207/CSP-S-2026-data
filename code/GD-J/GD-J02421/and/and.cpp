#include<iostream>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int maxn=-1;
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
		return 0;
	}
	if(m==2){
		int maxn=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,(a[i]&a[j]));
			}
		}
		cout<<maxn;
	}
	if(m==n){
		int res=a[1];
		for(int i=2;i<=n;i++){
			res=res&a[i];
		}
		cout<<res;
	}
	if(m==n-1){
		int res=a[1];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==1) res=a[2];
				if(i==2) res=a[1];
				if(i==j) continue;
				res=res&a[i];
			}
		}
		cout<<res;
	}
	return 0;
} 
