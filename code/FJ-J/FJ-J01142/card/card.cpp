#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,m,high=0,r=5;
int a[35][MAXN];
ll b[MAXN];
ll c[MAXN];
ll ans[35];
void chg(ll k,ll i){
	int j=0;
	while(k!=0){
		j++;
		a[j][i]=k%2;
		k/=2;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	//ÇåÁã 
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>b[i];
		chg(b[i],i);
	}

	for(int i=1;i<=30;i++){
		for(int j=1;j<=n;j++){
			c[i]+=a[i][j];
		}
	}
	
	cout<<"\n";

	for(int i=1;i<=32;i++){
		if(c[i]>=m) ans[i]=1,high=i;
		else{
			for(int j=1;j<=n;j++){
				a[i][j]=0;
			}
		}
	}
	int k=high;
	for(;high>=1;high--){
		if(ans[high]==0) continue;
		sort(a[high]+1,a[high]+r+1,[](const int b,const int c){
			return b>c;
		});
		int tmpr;
		for(int i=1;i<=r;i++){
			if(a[high][i]==0) break;
			if(a[high][i]==1) tmpr=i;
		}
		r=tmpr;
		if(r<m) ans[high]=0;
	}
	for(int i=1;i<=k;i++) ans[i]=a[1][i];
	cout<<"\n";
	for(int i=1;i<=r;i++){
		for(int j=1;j<=k;j++){
			ans[j]&=a[j][i];
		}
	}
	/*
	for(int i=1;i<=n;i++){
		if(b[i]==n) continue;
	}
	*/ 
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=30;j++){
			cout<<a[i][j];
		}
		cout<<"\n";
	}
	*/
	ll aaas=0;
	for(int i=1;i<=k;i++){
		aaas*=2;
		aaas+=ans[i];
	}
	cout<<"\n";
	cout<<aaas;
	return 0;
}
