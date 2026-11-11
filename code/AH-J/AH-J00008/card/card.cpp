#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vl=vector<ll>;
ll n,m;
bool f=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;vl a(n+1),t(m+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) f=0;
	}
	if(f==1){
		for(int i=1;i<=n;i++){
			vl zm(m+1,0);
			ll id=0;
			for(int j=i;j<=n;j++){
				ll l=1,r=id;
				while(l<r){
					ll m=l+(r-l)/2;
					if(zm[m]>=a[j]) r=m;
					else l=m+1;
				}
				if(zm[l]!=a[j]){
					id++;
					zm[id]=a[j];
				}else{
					id=l;
				}
			}
			for(int i=1;i<=id;i++)
				t[zm[i]]++;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			vl zm(m+1,0);
			ll id=0;
			for(int j=i;j<=n;j++){
				ll l=-1;
				for(int k=1;k<=id;k++){
					if(zm[k]==a[j]){
						l=k;
						break;
					}
				}
				if(l==-1){
					id++;
					zm[id]=a[j];
				}else{
					id=l;
				}
			}
			for(int i=1;i<=id;i++)
				t[zm[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<' ';
	}
	return 0;
}
