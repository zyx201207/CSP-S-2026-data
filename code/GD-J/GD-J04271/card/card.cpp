#include<bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

using std::string;

int n,m;

int ans[300005],a[300005];

int cnt,que[300005],flg[300005];

int last[300005],fa[300005];

int main(){
	std::ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;

	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=n;i>=1;i--){
//		cout<<last[a[i]]<<" ";
		if(last[a[i]]) fa[i]=fa[last[a[i]]];
		last[a[i]]=i;
	}
	for(int rnd=1;rnd<=n;rnd++){
		int i=rnd-1;
		do{
			ans[a[++i]]++;
//			cout<<i<<" ";
			while(fa[i]!=i){
				i=fa[i];
			}
			
		}while(i!=n);
//		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
