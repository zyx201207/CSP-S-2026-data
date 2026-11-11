#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],num[N],nt[N],ans[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		num[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		nt[i]=num[a[i]];
	}
	for(int i=1;i<=n;i++){
		int l=i;
		while(l<=n){
			if(nt[l]!=l){
				l=nt[l];
				continue;
			}
			ans[a[l]]++;
			l++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
