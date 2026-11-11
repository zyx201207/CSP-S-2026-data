#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+50;
int a[N];int n,m;
int fl[N];
int jl[N];
int find(int now){
	
	for(int i=now+1;i<=n;i++){
		if(a[i]==a[now]){
			fl[now+1]++;
			fl[i+1]--;
			return i;
		}
	} 
	return now+1;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int maxn=0;
	for(int i=1;i<=n;i++){
		//cout<<1<<" ";
		int last=i;
		for(int j=1;j<=n;j++)fl[j]=0;
		while(1){
			//cout<<last<<" "<<a[last]<<'\n';
			if(last==n+1){
				break;
			}
			last=find(last);
		}
		int ans=0;
		for(int j=i;j<=n;j++){
			fl[j]+=fl[j-1];
			//cout<<fl[j]<<" ";
			if(!fl[j]){
				//cout<<a[j]<<" ";
				jl[a[j]]++;
			}
		}
		//cout<<'\n';
		//cout<<ans<<" ";
		//jl[ans]++;
		//maxn=max(maxn,ans);
	}
	for(int i=1;i<=m;i++){
		cout<<jl[i]<<" ";
	}
	return 0;
}/*4 3
1 2 1 3
*//*
10 3
3 1 2 1 3 2 3 1 2 1*/
