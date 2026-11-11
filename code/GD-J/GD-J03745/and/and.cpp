#include<iostream>
using namespace std;
int n,m;
long long a[200003],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=30,cnt;i>=0;i--){
		cnt=0;
		for(int j=1;j<=n;j++){
			if(a[j]&(1ll<<i))cnt++;
		}
		if(cnt>=m){
			ans+=(1ll<<i);
			for(int j=1;j<=n;j++){
				if(!(a[j]&(1LL<<i))){
					a[j]=a[n];
					j--;n--;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
