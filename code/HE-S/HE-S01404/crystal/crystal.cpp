#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
int n;ll m,ans=1;
ll a[500001],pre[500001]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	for(int i=2;i<=n;i++){
//		for(int j=1;j<i;j++){
//			if(a[i]*(i-j+1)-pre[i]+pre[j-1]<=m){
//				ans=max(ans,(ll)i-j+1);
//				break;
//			}
//		}
		int id=1;
		for(int j=19;j>=0;j--){
			int pos=(1<<j);
			if(i>pos&&(a[i]*(i-pos+1)-pre[i]+pre[pos-1]<=m)){
				ans=max(ans,(ll)i-pos+1);
			}
		}
	}
	cout<<ans;
	return 0;
}
