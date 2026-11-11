#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n,m,a[500005],res[300005];
map <int,int> ma;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int k=i;k<=n;k++){
			if(ma[a[k]]==0){
				ma[a[k]]=k;
			}else{
				for(int l=ma[a[k]];l<=k-1;l++){
					ma[a[l]]=0;
				}
				ma[a[k]]=k;
			}
		}
		for(int k=1;k<=m;k++){
			if(ma[k]!=0){
				res[k]++;
			}
		}
		ma.clear();
	}
	for(int i=1;i<=m;i++){
		cout<<res[i]<<" ";
	}
}
