#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,tot,ans;
long long a[N],lqx[N],c_2[35]={1};
bool f[N];
void solve(int k){
	if(k<0) return;
	int cnt=0;
	for(int i=1;i<=tot;i++){
		if(f[i]==0&&(a[i]&c_2[k])==c_2[k]) cnt++;
	}
	if(cnt>=m){
		for(int i=1;i<=tot;i++){
			if(f[i]==0&&(a[i]&c_2[k])!=c_2[k]){
				f[i]=1;
			}
		}
		ans+=c_2[k];
	}
	solve(k-1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=30;i++) c_2[i]=c_2[i-1]*2;
	for(int k=30;k>=0;k++){
		tot=0;
		for(int i=1;i<=n;i++){
			if((a[i]&c_2[k])==c_2[k]){
				tot++;
				lqx[tot]=a[i];
			} 
		}
		if(tot>=m){
			ans+=c_2[k];
			solve(k-1);
			break;
		} 		
	}
	cout<<ans;
	return 0;
}