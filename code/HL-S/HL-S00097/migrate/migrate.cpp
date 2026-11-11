#include<iostream>
#define int long long
using namespace std;
int a[5000010];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n;
		int k;
		cin>>n>>k;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		if(a[1]-a[0]>k){
			cout<<0<<endl;
		}
		else{
			int c=k/(a[1]-a[0]);
			cout<<(n-c-1)<<endl;
		}
	}
}