#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],maxn,ans; 
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			ans=a[i];
		}
		maxn=max(maxn,a[i]);
		ans=a[i]&ans;
	}
	if(m==1){
		cout<<maxn;
	}else{
		if(m==2){
			sort(a+1,a+1+n,cmp);
			maxn=0;
			for(int i=1;i<32;i++){
				for(int j=i+1;j<=32;j++){
					maxn=max(maxn,a[j]&a[i]);
				}
			}
			cout<<maxn;
		}else{
			if(n==m){
				cout<<ans;
			}else{
				if(m==n-1){
					cout<<1;
				}else{
					sort(a+1,a+1+n,cmp);//          cjq
					maxn=a[1];
					for(int i=2;i<=m;i++){
						maxn=maxn&a[i];
					}
					cout<<maxn;
				}
			}
		}
	}
	return 0;
}
