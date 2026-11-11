#include<bits/stdc++.h>
using namespace std;
int n,d,a[2000001],cnt,vis[2000001],mx;
bool check(int qi,int z){
	int cnt1=0,mx=-1;
	for(int i=1;i<=n;i++)vis[i]=1e9;
	queue<int> q;
	q.push(qi);
	vis[qi]=0;
	while(q.size()){
		int x=q.front();
		q.pop();
		for(int i=1;i<=n;i++){
			if(abs(a[x]-a[i])<=d&&(vis[i]==1e9||vis[i]==vis[x]+1)){cout<<x<<" "<<i<<"\n";
				if(mx!=-1&&vis[x]==mx-1){
					if(i!=z)continue;
					cnt1++;
					continue;
				}
				if(i==z){
					mx=vis[x]+1;
					cnt1++;
					continue;
				}
				q.push(i);
				vis[i]=vis[x]+1;
			}
		}
	}
	//cout<<"\n"<<qi<<" "<<z<<" "<<mx<<"\n";
	return cnt1==2;
}
int main(){
	/*freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);*/
	int t;
	cin>>t>>t;
	while(t--){
		cin>>n>>d;
		cnt=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(check(i,j)){
					cnt++;
					//cout<<a[i]<<" "<<a[j]<<" "<<cnt<<"\n";
				}
			}
		}
		//cout<<cnt<<"\n";
	}
	return 0;
}
