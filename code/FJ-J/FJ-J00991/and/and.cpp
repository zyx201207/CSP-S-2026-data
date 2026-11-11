#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxn;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
	}else if(m==n){
		int c=a[1];
		for(int i=1;i<=n;i++){
			c=c&a[i];
		}
		cout<<c;
	}else if(m==n-1){
		int c;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					c=c&a[j];
				}
			}
			maxn=max(maxn,c);
		}
		cout<<maxn;
	}else if(m==2){
		int c;
		for(int i=1;i<=n;i++){
			c=a[i];
			for(int j=i+1;j<=n;j++){
				c=c&a[i]&a[j];
				maxn=max(maxn,c);
			}
		}
		cout<<maxn;
	}
	return 0;
}
