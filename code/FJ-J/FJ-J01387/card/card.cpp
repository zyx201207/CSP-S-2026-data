#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10; 
int n,m;
int a[N];
int nxt[M],to[N];
int ans[M];
bool flag[N]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		to[i]=nxt[a[i]];
		nxt[a[i]]=i;
	} 
	for(int _=1;_<=n;_++){
		for(int i=1;i<_;i++) flag[i]=true;
		for(int i=_;i<=n;i++) flag[i]=false;
		for(int i=_;i<=n;i++){
			if(!flag[to[i]]){
				for(int j=to[i];j<i;j++) flag[j]=true;
			}
		} 
		for(int i=1;i<=n;i++){
			if(!flag[i]) ans[a[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
