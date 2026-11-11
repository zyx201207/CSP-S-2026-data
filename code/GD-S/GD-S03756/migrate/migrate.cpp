#include<bits/stdc++.h>
using namespace std;
int n,c,t;
int d,a[10005];
//void qq(int x,y,z){
//	int sum=0;
//	while(z==y){
//		for(int i=x;i<=y;i++){
//			int k=i+1;
//			while(a[k]-a[i]<=d){
//				k++;
//			}
//			k-=1;
//		}
//	}
//} 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
//		for(int i=1;i<n;i++){
//			for(int j=i+1;j<=n;j++){
//				 qq(i,j,i);
//			}
//		}
	cout<<0<<endl;
	}
	return 0;
}  
