#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
long long isl[1000007];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    int a[t];
    for(int T=0;T<t;T++){
    	int n;
    	ll d;
    	cin>>n>>d;
    	cin>>isl[0];
    	for(int i=1;i<n;i++){
    		cin>>isl[i];
    		isl[i]+=isl[i-1];  //Ç°×ººÍ 
		}
		int ans=0;
		for(int bgn=0;bgn<n;bgn++){
			pii dp[n];    //first:path len,second:num of pth
			dp[bgn]={0,1};
			for(int i=bgn+1;i<n;i++){
				int l=bgn;
				int r=i;
				int mid=(l+r)/2;
				if(isl[i]-isl[bgn]<=d){
					dp[i].first=1;
					dp[i].second=1;
					continue;
				}
				while(l<r-1){
					mid=(l+r)/2;
					if(isl[i]-isl[mid]>d){  //can't fly from mid to i
						l=mid;
					}
					if(isl[i]-isl[mid]<=d){  //can fly from mid to i
						r=mid;
					}
				}
				dp[i].first=dp[r].first+1;
				dp[i].second=dp[r].second;
				cout<<i<<" "<<r<<endl;
				for(int j=1;j<4;j++){
					if(r+j>=i){
						break;
					}
					if(dp[r+j].first==dp[r].first){
						dp[i].second+=dp[r+j].second;
					}
				}
			}
			for(int i=bgn;i<n;i++){
				if(dp[i].second==2){
					ans++;
				}
			}
    	}
    	a[T]=ans;
	}
	for(int i=0;i<t;i++){
		cout<<a[i]<<endl;
	}
	return 0;
}
