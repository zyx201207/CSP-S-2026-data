#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long maxx=-1;
	long long ans=-1;
	long long maxxid;
	for(int i=1;i<=m;i++){
		if(i==1){
			for(int j=1;j<=n;j++){
				ans=max(ans,a[j]);
			}
		}else{
			maxx=-1;
			for(int j=1;j<=n;j++){
				if(maxx<=ans&a[j]){
					maxxid=j;
					maxx=ans&a[j];
				}
			}
			a[maxxid]=0;
			ans=maxx;
		}
	}
	cout<<ans;
	return 0;
}
