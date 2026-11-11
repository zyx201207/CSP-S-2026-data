#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=5*1e5;
int n,m,pw[MAXN+5],cf[MAXN+5],ned[MAXN+5]; 
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>pw[i];
		
	}
	sort(pw+1,pw+1+n);
	for(int i=2;i<=n;i++){
		cf[i]=pw[i]-pw[i-1];
		ned[i]=cf[i];
	}
	
//	for(int k=3;k<=n;k++){
//		
//		int flg=0;
//		//cout<<k<<":";
//		for(int i=n;i>=k;i--){
//			ned[i]=cf[i]*(k-1)+ned[i-1];
//			//cout<<ned[i]<<" ";
//			if(ned[i]<=m) flg=1;
//		}
//		int minn=1e18,mink;
//		for(int i=k-1;i<=n;i++){
//			if(minn>ned[i]){
//				minn=ned[i];mink=i;
//			}
//			
//		}
//		//cout<<k<<" "<<mink<<endl;
//		//cout<<endl;
//		if(flg==0){
//			cout<<k-1<<endl;
//			break;
//		}
//	}
	
	for(int i=3;i<=n;i++){
		ned[i]=cf[i]*(i-1)+ned[i-1];
		//cout<<ned[i]<<" "<<i<<endl;
		if(ned[i]>m){
			cout<<i-1<<endl;
			break;
		}
	}
	
	
	
	
	return 0;
}

