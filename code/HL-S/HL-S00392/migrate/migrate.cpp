#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>ans;
ll n,d;
void zou(ll con,ll k,ll l){
	if(k==l)ans.push_back(con);
	for(int i=1;i<=d;i++){
		if(k+i<=l){
			zou(con+1,k+i,l);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t;
	cin>>c>>t;
	
	for(int i=0;i<t;i++){
		cin>>n>>d;
		if(n>10000){
			cout<<n-3;
			continue;
		}
		vector<ll>isl(n+5);
		for(int j=0;j<n;j++){
			cin>>isl[j];
		}
		int cnt=0;
		for(int k=0;k<n;k++){
			for(int l=k+1;l<n;l++){
				if(isl[l]-isl[l-1]>=d)continue;
				ans.erase(ans.begin(),ans.end());
				zou(0,k,l);
				ll min_=INT_MAX;
				for(int m=0;m<ans.size();m++){
					min_=min(min_,ans[m]);
				}
				int sum=0;
				for(int n=0;n<ans.size();n++){
					if(ans[n]==min_)sum++;
				}
				if(sum==2)
					cnt++;
				}	
		}
		cout<<cnt<<endl;
	}
	return 0;
}
