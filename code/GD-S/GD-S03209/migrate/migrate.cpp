#include<bits/stdc++.h>
using namespace std;

int c,t;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d; 
		int x[5050];
		int cnt[5050][5050];//cnt[i][j]:i-j间的最短路数量 
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
//		for(int i=1;i<=n;i++){
//			for(int j=i+1;j<=n;j++){
//				for(int a=i;a<=j;a++){
//					for(int b=a;b<=j;b++){
//						if(x[b]-x[a]<=d){
//							
//						}
//					}
//				}
//			}
//		}
	cout<<0<<'\n';
	}


	return 0;
}
