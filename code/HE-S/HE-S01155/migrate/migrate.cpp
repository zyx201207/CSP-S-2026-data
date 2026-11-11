#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t,n,d,a[N],st,ans,cnt;
int small(int l,int r){
	int ans=1;
	for(int i=l;i<r;){
		int x=i;
		while(i<n && a[i+1]-a[x]<=d) i++;
		if(i==x) return -1;
		ans++;
	}
	return ans;
}
void dfs(int sum,int k,int r){
	//cout<<sum<<" "<<k<<" "<<r<<"\n";
	if(sum>st) return ;
	if(k>=r){
		cnt++;
		return ;
	}
	for(int i=k+1;i<=n && a[i]-a[k]<=d;i++){
		dfs(sum+1,i,r);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		//if(c==1 || c==2){
			for(int l=1;l<=n;l++){
				for(int r=l+3;r<=n;r++){
					st=small(l,r);
			//		cout<<"st:"<<st<<" "<<l<<" "<<r<<"\n";
					if(st==-1) continue;
					cnt=0;
					dfs(1,l,r);
					if(cnt==2) ans++;
				}
			}
			cout<<ans<<"\n";
	//	}
		
	}
	return 0;
}
