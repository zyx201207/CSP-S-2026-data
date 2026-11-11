#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,p;
ll a[500005],tab[300005],d[300005],num[300005];
bool d_[300005],flag=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		d_[a[i]]=1;
	}
	for(int i=0,j=0;i<300005;i++) if(d_[i]) num[j++]=i;
	ll i=0;
	for(int i=0;i<n;i++){
		p=0;
		for(int j=i;j<n;j++){
			if(a[j]==0) continue;
			cout<<a[j]<<" | ";
			for(int k=0;k<=p;k++){
				if(tab[k]==a[j]){
					for(int l=k;l<p;l++){
						for(int o=0;o<n;o++){
							if(a[o]==tab[l]){
								a[o]=0;
								break;
							}
						}
					}
					p=k;
					
					
					
					break;
				}
			}
		tab[p++]=a[j];
		for(int j=0;j<=p;j++){
			d[tab[p]]++;
		}
	}
	for(int i=0;i<m;i++){
		cout<<d[num[i]]<<" ";
	}
	return 0;
}}

