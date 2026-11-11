#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;
int n,m;
int a[N]; 
int ans[N];
int len[N];
int dif[N];
bool lst[N];
bool A=1,B=1;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=2;i<=n;i++) A&=(a[i]>=a[i-1]);
	int cntB=0;
	for(int i=2;i<=n;i++) cntB+=(a[i]!=a[i-1]);
	B&=(cntB<=10000);
	if(A){
		int cnt=1;
		for(int i=2;i<=n;i++){
			if(a[i]==a[i-1]) cnt++;
			else len[a[i-1]]=cnt, cnt=1;
		}
		len[a[n]]=cnt;
		cnt=1;
		dif[1]++;
		dif[a[1]+1]++;
		if((len[a[1]]-1)&1) ans[a[1]]++;
		for(int i=2;i<=n;i++){
			if(a[i]==a[i-1]) cnt++;
			else cnt=1;
			dif[a[i]+1]++;
			if((len[a[i]]-cnt)&1) ans[a[i]]++;
		}
		for(int i=1;i<=m;i++){
			dif[i]+=dif[i-1];
			if(len[a[i]]&1) ans[i]+=dif[i];
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
		return ;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(lst[a[j]]){
				for(int k=j-1;k>=i;k--){
					lst[a[k]]=0;
					if(a[k]==a[j]) break;
				}
			}
			lst[a[j]]=1;
		}
		if(n<m){
			for(int j=1;j<=n;j++){
				if(lst[a[j]]) ans[a[j]]++;
				lst[a[j]]=1;
			}
		}else{
			for(int j=1;j<=m;j++){
				if(lst[j]) ans[j]++;
				lst[j]=0;
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return ;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T=1; //cin>>T;
	while(T--) solve();
	return 0;
} 
