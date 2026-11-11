#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[200005];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
	    int maxn=0; 
	    for(int i=1;i<=n;i++){
		    maxn=max(maxn,a[i]);
	    }
		cout<<maxn;
	}else if(m==2){
		int maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,a[i]&a[j]);
			} 
		}
		cout<<maxn;
	}else if(m==n){
		int maxn=a[1];
		for(int i=2;i<=n;i++){
			maxn=maxn&a[i];
		}
		cout<<maxn;
	}
	return 0;
}  
