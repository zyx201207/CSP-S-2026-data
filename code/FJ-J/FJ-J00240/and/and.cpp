#include<iostream>
using namespace std;
long long a[200005];
bool vis[200005];
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
//	freopen("and5.in","r",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ans=0;
	for(int i=35;i>=1;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(vis[j]) continue;
			if(((a[j]>>(i-1))&1)==1) cnt++;
		}
		if(cnt>=m){
			ans+=(1<<(i-1));
//			cout<<i<<" "<<cnt<<" "<<ans<<" "<<(1<<(i-1))<<endl;
			for(int j=1;j<=n;j++){
				if(((a[j]>>(i-1))&1)==0) vis[j]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}

