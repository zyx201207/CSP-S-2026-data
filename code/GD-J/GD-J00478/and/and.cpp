#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e5+100;
int n,m;
int a[N],c[N];
int ans=0;
map<int,int>t;
int cnt=0;
map<int,int>vis;
void db(int x){
	while(x>0){
		t[x]++;
		
		if(t[x]>=m&&vis[x]==0){
			vis[x]=1;
			cnt++;
			c[cnt]=x;
		}x=x/2;
	}	
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		db(a[i]);
	}
	
	for(int i=1;i<=cnt;i++){
		
		ans=max(ans,c[i]);
	}
	cout<<ans;
	return 0;
} 
