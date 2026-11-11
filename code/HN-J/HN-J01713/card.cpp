#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const long long inf=1e13;
const int N=5e5+10;
int a[N],t[N],ans[N];
bool in[N];
int n,m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	bool taskA=1;
	bool taskB=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i],taskA=taskA&&(a[i-1]<=a[i]);
	if(taskA){
		for(int i=1;i<=n;i++)
			if(a[i+1]!=a[i]) cout<<i<<' ';
		return 0;
	}for(int i=1;i<=n;i++){
		memset(in,0,sizeof(in));
		for(int j=i;j<=n;j++){
			if(in[a[j]])
				for(int k=j-1;k>=i;k--){
					if(!in[a[k]]) continue;
					in[a[k]]=0;
					ans[a[k]]--;
					if(a[k]==a[j]) break;
				}
			in[a[j]]=1;
			ans[a[j]]++;
//			cout<<i<<' '<<j<<' '<<ans[1]<<' '<<in[1]<<endl;
//			cout<<i<<' '<<j<<' '<<ans[1]<<endl;
		}
	}for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
}/*

*/
