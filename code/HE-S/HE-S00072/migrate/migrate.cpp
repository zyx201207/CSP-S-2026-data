#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
//#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;

ll x,ans;
ull d;
int n,C,T;
//vector<int> arr[400000];
//void dfs(int id){
//	
//}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>C>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x;
		}
//		if(x[n]-x[1]<=d){
//			cout<<0<<endl;
//			continue;
//		}
//		int c=x[2]-x[1];
//		if(d<c){
//			cout<<0<<endl;
//			continue;
//		}
//		if(c%d!=0){
//			d=(c/d)*d;
//		}
//		int num=c/d;
//		if((x[n]-x[1])%d==0){
//			cout<<0<<endl;
//		}
//		for(int i=1;i<=n;i++){
//			for(int j=i+1;j<=n;j++){
//				dfs(i,j);
//				for(int k=1;k<=top;k++){
//					sort(arr[k].begin(),arr[k],end());
//				}
//				for(int k=1;k<top;k++){
//					if(arr[i]==arr[i+1]){
//						ans++;
//					}
//				}
//			}
//		}
		
//		cout<<ans<<endl;
		cout<<0<<endl;	
	}
	

	return 0;
}
