#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int ans[N];
int a[N];
int tans[N];
int id[N];
int f[N];
struct node{
	int x,id;
};
stack<node> q;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		if(!f[a[i]]){
			ans[i]++;
			id[i]=i+1;
		}else{
			ans[f[a[i]]]++;
			id[i]=f[a[i]];
		}
		f[a[i]]=i;
	}	
	for(int i=1;i<=n;i++){
		ans[id[i]]+=ans[i];
	}
	memset(f,0,sizeof(f));
	for(int i=n;i>=1;i--){
		if(!f[a[i]]){
			tans[a[i]]+=ans[i];
		}
		f[a[i]]=i;
	}	
	for(int i=1;i<=m;i++){
		cout<<tans[i]<<" ";
	}
	return 0;
}
