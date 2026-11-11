#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=5e5,MAXM=3e5;
ll a[MAXN+5],has[MAXM+5],desk[MAXN+5],endpt,ans[MAXM+5];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(endpt=1;endpt<=n;endpt++)
		cin>>a[endpt];
//	O(n^3/4) 24'
	for(ll i=1;i<=n;i++){
		endpt=n+1;
		for(ll k=i;k<=n;k++){
			//put a[k]
			if(has[a[k]]){
				for(ll stp=has[a[k]]+1;stp<=endpt;stp++){
					has[desk[stp]]=0;
					desk[stp]=0;
				}
				endpt=has[a[k]]+1;
			}else{
				has[a[k]]=endpt;
				desk[endpt++]=a[k];
			}
		}
		for(ll num=1;num<=m;num++)
			if(has[num])ans[num]++;
		memset(desk,0,MAXN+4);
		memset(has,0,MAXM+4);
	}for(ll i=1;i<=m;i++)
		cout<<ans[i]<<' ';
}
