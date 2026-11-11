#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],ans[300005],lst[500005],st[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<n<<endl;
		return 0;
	}
	if(m==2){
		ll l=n,r=n;
		if(a[n]==1){
			for(ll i=1;i<=n;i++){
				if(a[i]==1)r--;
			}
		}
		else{
			for(ll i=1;i<=n;i++){
				if(a[i]==2)l--;
			}
		} 
		cout<<l<<" "<<r<<endl;
		return 0;
	}
	for(ll i=1;i<=n;i++){
		ll id=0;
		for(ll j=1;j<=m;j++)lst[j]=0,st[j]=0;
		for(ll j=i;j<=n;j++){
			if(lst[a[j]]==0){
				lst[a[j]]=j;
				st[++id]=a[j];
			}
			else{
				for(ll k=lst[a[j]]+1;k<=id;k++){
					lst[st[k]]=0;
					st[k]=0;
				}
				id=lst[a[j]];
			}
		}
		for(ll j=1;j<=id;j++){
			ans[st[j]]++;
		}
	}
	for(ll i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}