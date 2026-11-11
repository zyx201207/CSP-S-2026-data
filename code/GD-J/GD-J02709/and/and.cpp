#include<iostream>
#define N 200005
using namespace std;
int n,m,a[N],maxn=0,ans=0,cnt=0,ch[N][31];
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		cout<<maxn;
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			 for(int j=i+1;j<=n;j++){
			 	ans=max(a[i]&a[j],ans);
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n-m+1;i++) cout<<1;
	return 0;
}
