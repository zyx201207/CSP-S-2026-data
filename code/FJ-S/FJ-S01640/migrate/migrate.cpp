#include<bits/stdc++.h>
#define long long ll
using namespace std;
const int N=2e6+10;
int c,T;
int a[N];
int n,d;
int wc(int u,int x){
	for(int i=u+1;i<=n;i++){
		if(a[i]-a[u]==x) return 1;
		if(a[i]-a[u]>x) return 0;
	}
	return 0;
}
int gunmu(int u,int x){
	int cnt=0;
	for(int i=1;i<x;i++){
		if(wc(u,i)==1) cnt++;
		if(cnt>2) return 0;
	}
	if(cnt==2) return 1;
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		int i,j;
		int ans=0;
		cin>>n>>d;
		for(i=1;i<=n;i++){
			cin>>a[i];
		}
		for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				int juli=a[j]-a[i];
				if(juli>d){
					if(gunmu(i,juli)==1){
						cout<<a[i]<<" "<<a[j]<<endl;
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

