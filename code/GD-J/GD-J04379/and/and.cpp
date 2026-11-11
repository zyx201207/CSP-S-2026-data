#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
long long a[200005];
long long f[35],cnt[35]={0},vis[200005]={0};
priority_queue<int> js[35];
void er(int x){
	int k=x;
	for(int i=30;i>=0;i--){
		if(x>=f[i]){
			x-=f[i];
			cnt[i]++;
			js[i].push(k);
		} 
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	f[0]=1;
	for(int i=1;i<=30;i++){
		f[i]=f[i-1]<<1;
		cnt[i]=0;
	}
	for(int i=1;i<=n;i++){
		vis[i]=0;
		cin>>a[i];
		er(a[i]);
	}
	ans=-1;
	for(int i=30;i>=0;i--){
		if(cnt[i]>=m){
			while(m--){
				int t=js[i].top();
				js[i].pop();
				if(ans==-1){
					ans=t;
				}else{
					ans=(ans&t);
				}
			}
			break;
		}
	}
	cout<<ans;
	return 0;
} 
