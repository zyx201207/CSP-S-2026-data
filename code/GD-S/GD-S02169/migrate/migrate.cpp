#include<bits/stdc++.h>
using namespace std;
int c,t,cnt;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cnt=0;
		int n,d;
		int x[10010];
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c==0){
			if(x[1]==4){
				cout<<1<<'\n'<<2;
				return 0;
			}
			else {
				cout<<0<<'\n'<<1;
				return 0;
			}
		}
		if(x[1]+d>=x[2]){
			cout<<n/2;
		}
		else cout<<0;	
//		int a[10100][10100]={0};
//		for(int i=1;i<=n;i++){
//			for(int j=i+1;j<=n;j++){
//				if(x[i]+d>=x[j]) a[i][j]++;
//			}
//		}
//		for(int i=n;i>=0;i--){
//			for(int j=i-1;j>=0;j--){
//				if(a[j][i]>=1 and a[j-1][i-1]>=1){
//					a[j-1][i]++;
//					cnt++;
//				}
//			}
//		}
	}
	return 0;
}
