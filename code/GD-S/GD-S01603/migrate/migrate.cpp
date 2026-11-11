#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t,d,n,ans,a[N];
bool chk(int x){
	if(a[x]-a[x-1]<=d&&a[x-1]-a[x-3]<=d&&a[x]-a[x-2]<=d&&a[x-2]-a[x-3]<=d){
		return true;
	}
	return false;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
//		int pos=1;
//		bool f=1;
//		vector<int> v;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>=4&&a[i]-a[i-3]>d){
//				cout<<a[i-3]<<" "<<a[i]<<endl;
				if(chk(i)){
					ans++;
				}
			}
			if(i>=3&&a[i]-a[i-2]<=d){
				ans++;
			}
//			if(i==1){
//				v.push_back(i);
//			}
//			if(f&&a[i]-a[pos]>d){
//				if(v[v.size()-1]==i-1){
//					f=0;
//					continue;
//				}
//				v.push_back(i-1);
//				pos=i-1;
//			}
		}
//		if(a[n]-a[v[v.size()-1]]<=d){
//			v.push_back(n);
//		}
//		for(int i=0;i<v.size();i++){
//			cout<<v[i]<<" ";
//			if(i>=3){
//				if(chk(i)){
//					ans++;
//				}
//			}
//		}
//        for(int i=1;i<=n;i++){
//        	for(int j=1;j<=n;j++){
//        		for(int k=i+1;k<j;k++){
//        			
//				}
//			}
//		}
        if(n==1||n==2){
        	cout<<0<<'\n';
		}else{
			cout<<ans<<'\n';
		}
		
	}
	return 0;
} 
