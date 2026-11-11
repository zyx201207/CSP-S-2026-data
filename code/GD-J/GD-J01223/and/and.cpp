# include<bits/stdc++.h>
# define int long long
using namespace std;
vector<int>A,B;
int n,ipt,m,ans,cnt;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>ipt,A.push_back(ipt);
	for(int i=30;i>=0;i--){
		cnt=0;
		
		for(int j:A)if(j>>i&1)cnt++;
		
		if(cnt>=m){
			for(int j:A)if(j>>i&1)B.push_back(j);
			A=B,B.clear(),ans|=1<<i;
		}
	}
	cout<<ans;
}
