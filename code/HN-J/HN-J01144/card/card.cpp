#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],i;
map<int,int>mp1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int j=1;j<=n;j++){
		map<int,int>mp;
		int v[N];
		for(int i1=j;i1<=n;i1++){
			if(mp[a[i1]]==1){
				for(i;i>=0;i--){
					if(v[i]==a[i1]){
						break;
					}else{
						v[i]==0;
						mp[v[i]]=0;
					}
				}
			}else{
				i++;
				v[i]=a[i1];
				mp[v[i]]==1;
			}
		}
		int b[N];
		for(int k=1;k<=m;k++){
			if(b[i]==0&&mp[i]>=1){
				mp1[i]++;
				b[i]==1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<mp1[i]<<' ';
	}
	return 0;
}
