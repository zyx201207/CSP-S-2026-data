#include<bits/stdc++.h>
using namespace std;
int n,m;
int N[500005];
int ju[500005];
bool flag[500005];
int ans[300005];
int mp[300005];
int mp2[300005];
void solve(){
	for(int i=n;i>=1;i--){
		for(int j=1;j<=m;j++) mp2[j]=0;
		for(int j=i;j<=n;j++){
			flag[j]=0;
			ju[j]=0;
		}
		for(int j=1;j<=m;j++) mp[j]=0;
		for(int j=i;j<=n;j++){
			if(mp[N[j]]){
				for(int t=mp[N[j]];t<j;t++){
					if(ju[t]) t=ju[t];
					flag[t]=1;
					mp[N[t]]=0;
				}
				ju[mp[N[j]]]=j;
			}

			mp[N[j]]=j;
		}
		for(int j=i;j<=n;j++){
			if(!flag[j]){
				if(!mp2[N[j]]){
					ans[N[j]]++;
					mp2[N[j]]=1;
				}
			}
		}
	}
}
void solve2(){
	ans[N[n]]=n;
	int pos=0;
	for(int j=n-1;j>=1;j--){
		if(N[j]!=N[n]){
			pos=j;
			break;
		}
	}
	for(int j=pos;j>=1;j--){
		if(N[j]==N[pos]) ans[N[j]]++;
	}
}
void solve3(){
	for(int i=1;i<=n;i++){
		if(N[i]!=N[i+1]) ans[N[i]]=i;
	}
}
bool flag2=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		 cin>>N[i];
		 if(N[i]<N[i-1]) flag2=0;
	}
	if(m<=2) solve2();
	else if(flag2) solve3();
	else solve();
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
