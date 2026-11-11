#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN=5e5+5,MAXM=3e5+5;
int cnt[MAXM],a[MAXN];
int v_cnt[MAXM],vis[MAXN],pos[MAXN];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			v_cnt[j]=0;
		for(int j=i;j<=n;j++)
			vis[j]=1;
		for(int j=i;j<=n;j++){
			if(v_cnt[a[j]]!=0){
				for(int k=pos[a[j]];k<j;k++){
					v_cnt[a[k]]--,vis[k]=0;
				}
			}
			v_cnt[a[j]]++;
			pos[a[j]]=j;
		}
		for(int j=i;j<=n;j++){
			if(vis[j]){
				cnt[a[j]]++;
			}
		}
		cout<<'\n';
	}
	for(int i=1;i<=m;i++)
		cout<<cnt[i]<<" ";
}
/*
4 3
1 2 1 3
*/
