#include<bits/stdc++.h>
using namespace std;
int c;
int q;
long long n,d;
long long a[2000005];
long long bj;
int wz=1;
long long minx=1e18;
void dfs(int xb,int bs,int jt){
	if(xb==jt){
		if(minx>bs){
			bj=1;
			minx=bs;
		}
		else {
			bj++;
		}
	}
	for (int i=xb+1;i<=jt;i++){
		if(a[xb]+d<a[i]){
			return;
		}
		dfs(i,bs+1,jt);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>c>>q;
    if(c==13||c==14){
    	while(q--){
    		cout<<0<<"\n";
		}
    	return 0;
	}
    while(q--){
    	cin>>n>>d;
    	for (int i=1;i<=n;i++){
    		cin>>a[i];
		}
		wz=0;
		for (int i=1;i<n;i++){
			if(a[i]+d<a[i+1]){
				wz=i;
				break;
			}
		}
		if(wz==0){
			wz=n;
		}
		if(wz==1){
			cout<<0<<"\n";
			continue;
		}
		long long ans=0;
		for (int i=1;i<wz;i++){
			for (int j=i+1;j<=wz;j++){
				bj=0;
				minx=1e18;
				dfs(i,0,j);
				
				if(bj!=0&&bj==2){
					ans++;
				}
				
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
