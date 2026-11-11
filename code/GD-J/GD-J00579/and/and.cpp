#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int maxn=0,z;
	int a[200005]={};
//	vector<int> a(n+1);
	for(int i=1;i<=n;++i){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	if(m==n){
		z=a[1];
		for(int i=1;i<=n;++i){
			z=z&a[i];
		}
		cout<<z;
		return 0;
	}
	if(m==2){
		maxn=0;
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==n-1){
		maxn=0;
		int x;
		for(int i=1;i<=n;++i){
			if(i==1){
				x=a[2];
			}else{
				x=a[1];
			}
			for(int j=1;j<=n;++j){
				if(i==j){
					continue;
				}
				x=x&a[j];
			}
			maxn=max(maxn,x);
		}
		cout<<maxn;
		return 0;
	}
	cout<<0;
}
