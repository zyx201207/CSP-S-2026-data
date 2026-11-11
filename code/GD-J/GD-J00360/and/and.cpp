#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,m,a[maxn],bk[maxn],bk2[maxn],ans=-1;
priority_queue<int> pq;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	memset(bk,1,sizeof(bk));
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=30;i>=0;i--){
		int w=(1<<i);
		for(int j=1;j<=n;j++){
			if((a[j]&w)==w){
				pq.push(j);
			}
		}
		memset(bk2,0,sizeof(bk2));
		int cnt=0;
		while(!pq.empty()){
			if(bk[pq.top()]){
				bk2[pq.top()]=1;cnt++;
			}
			pq.pop();
		}
		if(cnt>=m){
			memcpy(bk,bk2,sizeof(bk2));
		}
	}
	for(int i=1;i<=n;i++){
		if(bk[i]){
			if(ans==-1)ans=a[i];
			else ans&=a[i];	
		}
	}
	cout<<ans;
	return 0;
}
