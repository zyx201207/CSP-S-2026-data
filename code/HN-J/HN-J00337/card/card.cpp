#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],lst[N],cnt,ans[N],t[N];
bool vis[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int k=1;k<=n;++k){
//		cout<<"µÚ"<<k<<"ÂÖ:\n";
		cnt=0;
		for(int i=1;i<=m;++i)lst[i]=-1,vis[i]=0;
		for(int i=1;i<=n;++i)ans[i]=0;
		for(int i=k;i<=n;++i){
			if(lst[a[i]]==-1){
//				if(i==7)cout<<lst[a[i]]<<"\n";
				ans[++cnt]=a[i],lst[a[i]]=cnt;
			}else{
				cnt=lst[a[i]];
//				cout<<i<<" "<<lst[2]<<" ";
				for(int j=cnt;j<i;++j)lst[a[j]]=-1;//!!!
//				cout<<cnt<<" "<<i-1<<"\n";
				lst[a[i]]=cnt;
//				cout<<a[i]<<" "<<lst[a[i]]<<"\n"; 
				ans[cnt]=a[i];
			}
//			cout<<i<<" "<<cnt<<" "<<lst[a[i]]<<" "<<ans[cnt]<<"\n";
		}
		for(int i=1;i<=cnt;++i){
			if(!vis[ans[i]])++t[ans[i]],vis[ans[i]]=1; 
		}
//		for(int i=1;i<=cnt;++i)cout<<ans[i]<<" ";
//		cout<<"\n-----------------------------\n";
	}
	for(int i=1;i<=m;++i)cout<<t[i]<<" ";
	return 0;
}
/*
7 3
1 1 2 1 1 2 3

9 3
1 2 1 3 2 3 1 2 1

10 3
3 1 2 1 3 2 3 1 2 1

5 3
2 3 1 2 1
*/
