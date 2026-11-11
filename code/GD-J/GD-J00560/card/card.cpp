#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],lst[N],ans[M],now[M];
bool is[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i;i--){
		lst[i]=lst[now[a[i]]];
		now[a[i]]=i;
	}
	for(int i=n;i;i--){
		for(int j=1;j<=m;j++) is[j]=0;
		for(int j=i;j<=n;j++){
			if(!is[a[j]]){
				ans[a[j]]++,is[a[j]]=1;
//				cout<<i<<' '<<a[j]<<'\n';
			}
			if(lst[j])j=lst[j]-1;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
