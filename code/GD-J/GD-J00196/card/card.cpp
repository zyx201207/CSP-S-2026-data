#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define ll long long
using namespace std;
int n,m;
int a[500005];
int nxt[500005],pre[500005],ans[500005];
vector<int> v[300005];
int f[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int fl=0;
	for(int i=1;i<=n;i++){
		cin>>a[i],nxt[i]=i+1;
		if(i!=1&&a[i]<a[i-1]){
			fl=1;
		} 
	}
	if(!fl){
		for(int i=1;i<=n;i++)
			pre[a[i]]=i;
		for(int i=1;i<m;i++)
			cout<<pre[i]<<' ';
		cout<<pre[m]<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(pre[a[i]]){
			nxt[pre[a[i]]]=i;
		}
		pre[a[i]]=i;
	}
//	for(int i=1;i<=n;i++)
//		cout<<nxt[i]<<' ';
//	cout<<endl; 
//	for(int i=1;i<=n;i=nxt[i]){
//		if(a[nxt[i]]!=a[i]){
////			cout<<i<<endl;
//			ans[a[i]]++; 
//			f[i]=1;
//		}
//	} 
//	for(int i=1;i<=m;i++)
//		ans[i]+=(pre[i]-1);
	for(int i=1;i<=n;i++){
//		if(f[i])
//			ans[a[i]]-=(n-i); 
		for(int j=i;j<=n;j=nxt[j]){
			if(a[nxt[j]]!=a[j]){
//				cout<<a[j]<<' ';
				ans[a[j]]++;
			}
		}
//		cout<<endl;
	}
	for(int i=1;i<m;i++)
		cout<<ans[i]<<' ';
	cout<<ans[m]<<endl;
	return 0;
} 
