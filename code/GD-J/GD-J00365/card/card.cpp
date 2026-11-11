#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500005],t[300005],sum[300005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll tt=1;tt<=n;tt++){
		for(ll i=tt;i<=n;i++){
			if(t[a[i]]==0){
				t[a[i]]=a[i];
			}
			else{
				for(ll j=i-1;a[j]!=a[i];j--){
					t[a[j]]=0;
				}
			}
		}
		
		for(ll i=1;i<=m;i++){
			if(t[i]!=0){
				sum[t[i]]++;
				t[i]=0;
			}
		}
	}
	for(ll i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
