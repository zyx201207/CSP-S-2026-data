#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+10;
ll n,flag[N],sum,m;
ll a[N],t[N],p[N];
char c[N];
string s,s1;
ll ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++){
			if(t[a[j]]==0){
				t[a[j]]=1;
				flag[a[j]]=j;
			}
			else{
				for(ll k=flag[a[j]];k<=j;k++){
					t[a[k]]=min(t[a[k]],(ll)0);
				}
				t[a[j]]=1;
			}
		}
		for(ll j=1;j<=m;j++){
			if(t[j])ans[j]++;
		}
		for(ll i=1;i<=n;i++)t[i]=0;
		for(ll i=1;i<=n;i++)flag[i]=0;
	}
	for(ll i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	} 
	return 0;
}
