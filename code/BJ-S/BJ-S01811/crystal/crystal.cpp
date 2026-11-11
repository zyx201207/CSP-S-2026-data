#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n,m;
	
	cin>>n>>m;
	
	vector<int>a(n+1,0);
	
	for(int i=1;i<=n;i++) cin>>a[i];

	sort(a.begin()+1,a.end());
		
	int r=1,tmp=0,ans=0;
	
	for(int i=1;i<=n;i++){
		if(i!=1) tmp-=a[r]-a[i-1];
		
		while(true){
			if(r==n) break;
			
			int add=(r-i+1)*(a[r+1]-a[r]);

			if(tmp+add<=m){
				tmp+=add;
				r++;
			}else break;
		}

		ans=max(ans,r-i+1);
	}
	
	cout<<ans<<endl;
}
