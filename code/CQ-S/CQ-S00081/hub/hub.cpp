#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,k,six[1000001];
bool check(long long mid){
	
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		vector <long long> v[1000001];
		for(int i=1;i<=n;i++){
			long long x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		long long l=0,r=n,mid,ans=1;
		while(l<=r){
			if(check(mid)){
				r=mid-1;
				ans=mid;
			}
			else l=mid+1;
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++){
		v[i].clear();	
		six[i]=0;	
		}
	}
	return 0; 
} 
