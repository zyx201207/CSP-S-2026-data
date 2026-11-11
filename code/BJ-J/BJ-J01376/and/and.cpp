#include<iostream>
using namespace std;
int n,m,a[200005];
bool b[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) b[i]=true;
	int ans=0;
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(!b[j]) continue;
			if((a[j]>>i)&1) cnt++;
		}
		if(cnt>=m){
			for(int j=1;j<=n;j++){
				if(!b[j]) continue;
				if(((a[j]>>i)&1)==0) b[j]=false;
			}
			ans+=(1<<i);
		}
	}
	cout<<ans<<'\n';
	return 0;
}
		
