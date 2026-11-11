//GZ-J00173  遵义航天高级中学  刘鑫馨
#include<bits/stdc++.h> 
using namespace std;
#define int long long
signed main(){
	freopen ("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[200005],maxx=0;
	int ans;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans=(ans&a[i]);
		maxx=max(maxx,a[i]);
	}
	sort(a+1,a+n+1);
	if(m==n){
		cout<<ans;
		return 0;
	}else if(m==1){
		cout<<maxx;
	}else if(m==2){
		int mj=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					mj=max(mj,(a[i]&a[j]));
				}
			}
		}
		cout<<mj;
	}else{
		cout<<0;
	}
	return 0;
}
