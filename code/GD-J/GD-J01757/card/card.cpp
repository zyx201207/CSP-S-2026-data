#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=5e5+10;
const int M=1e6+10;
const int K=15;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
int n,m;
int a[N];
bool vis[N];
int tmp[N],lst[N],cnt[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
//	if(n<=5000){
		int tot;
		for(int i=n;i>=1;--i){
			tot=0;
			for(int j=1;j<=m;++j)vis[j]=0,lst[j]=0;
			for(int j=i;j<=n;++j){
//				cout<<"now:"<<a[j]<<endl;
				if(lst[a[j]]==0){
//					cout<<"new!"<<endl;
					tmp[++tot]=a[j];
					lst[a[j]]=tot;
					vis[a[j]]=1;
//					continue;
				}else{
					for(int k=lst[a[j]]+1;k<=tot;++k){
						vis[tmp[k]]=0;
						lst[tmp[k]]=0;
					}
					tot=lst[a[j]];
				}
//				cout<<"tot:"<<tot<<endl;
//				for(int k=1;k<=tot;++k){
//					cout<<tmp[k]<<" ";
//				}
//				cout<<endl;
			}
			
//			cout<<endl;
			for(int j=1;j<=m;++j){
				if(vis[j])cnt[j]++;
			}
		}
		for(int i=1;i<=m;++i){
			cout<<cnt[i]<<" ";
		}
		return 0;
//	}
}
/*
10 3
3 1 2 1 3 2 3 1 2 1

*/
