#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],c,k[500005];
map<int,int>mp;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(mp[a[i]]==0)c++;
		mp[a[i]]++;
	}
	map<int,int>b;
	while(m--){
		for(int i=1;i<=n;i++){
			k[a[i]]++;
			if(k[a[i]]==2){
				memset(k,0,sizeof(k));
				k[a[i]]++;
			}
		}
		for(int i=1;i<=c;i++){
			if(k[i]!=0)b[i]++;
		}
	}
	for(int i=1;i<=c;i++){
		cout<<b[i]<<' ';
	}
	return 0;
}
