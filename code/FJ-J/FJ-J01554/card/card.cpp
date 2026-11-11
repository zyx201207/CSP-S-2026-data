#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5e5+10;
int n,m;
int a[N],b[N];
int ton[N];
int t[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=n;i>0;--i){
		if(!t[a[i]]) b[i]=0;
		else b[i]=t[a[i]];
		t[a[i]]=i;
	}
	for(int i=1;i<=n;++i){
		int j=i; 
		while(j<=n){
			if(b[j]!=0) j=b[j];
			else{
				ton[a[j]]++;
				j++;
			}
		}
	}
	for(int i=1;i<=m;++i) printf("%lld ",ton[i]);
	return 0;
}

