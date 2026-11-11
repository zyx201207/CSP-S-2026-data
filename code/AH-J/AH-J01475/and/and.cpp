#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int a[N];

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	int m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+1+n);
		cout<<a[n];
	}else if(m==2){
		int maxn=-1;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				int c=a[i]&a[j];
				maxn=max(maxn,c);
			}
		}
		cout<<maxn;
	}else if(m==n){
		int e=a[1]&a[2];
		for(int i=3;i<=n;i++){
			e=e&a[i];
		}
		cout<<e;
	}
	return 0;
}
