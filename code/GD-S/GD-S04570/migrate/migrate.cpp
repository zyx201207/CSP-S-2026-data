#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e7+10;
int a[N];
int c,t,n,d;
int ans;
void search(int ed){
	bool flag=false;
	queue<int> q;
	q.push(a[1]);
	while(!q.empty()){
		int cur=q.front();q.pop();
		if(cur==a[ed]&&!flag) flag==true;
		else if(cur==a[ed]&&flag) ans++;
		else		
		for(int i=cur+1;i<=ed;i++){
			if(a[i]-a[cur]<=d){
				q.push(a[cur]);
			}
		}
	}
}
signed main(){
	   freopen("migrate.in","r",stdin);
	   freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;	
		ans=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=2;i<=n;i++){
			search(i);
		}
	
		cout<<ans<<endl;
	}
	return 0;
}

