#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[500001];
bool vis[500001];
int ans[500001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	int t[m+10];
	memset(t,0,sizeof(t));
	ll cnt=0;
	int tmp=n;
	ll des[500001];
	memset(des,0,sizeof(des));
	for(int i=1;i<=n;i++){
		memset(des,0,sizeof(des));
		memset(t,0,sizeof(t));
		memset(vis,1,sizeof(vis));
		ll pos=0;
		for(int j=i;j<=n;j++){
			if(vis[a[j]] && t[a[j]]==0){
				des[++pos]=a[j];
				t[a[j]]=pos;
			}else if(vis[a[j]] && t[a[j]]!=0){
				for(int k=t[a[j]];k<=n;k++){
					
					vis[des[k]]=0;des[k]=0;
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(!t[1]){
				ans[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
}