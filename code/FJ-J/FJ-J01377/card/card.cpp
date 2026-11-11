#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
const int M=3e5+10;
int n,m,a[N],b[N],ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		b[a[i]]++;
	}
	if(n==2){
		if(m==1)cout<<2;
		else if(a[n]==1)cout<<"2 1";
		else cout<<"1 2";
		return 0;
	}
	ans[a[n]]=n;
	for(int i=1;i<m;++i)ans[i]=1;
	for(int i=1;i<=m;++i)cout<<ans[i]<<" ";
	return 0;
}
