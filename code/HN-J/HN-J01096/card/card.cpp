#include<bits/stdc++.h>
using namespace std;
const int N=5e6+5;
int n,m,a[N],b[N],hh;
map<int,int>mp,ans;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		hh=0;
		mp.clear();
		for(int j=i;j<=n;j++){
			if(mp[a[j]]){
				int h=mp[a[j]]-1;
				for(int k=mp[a[j]];k<=hh;k++){
					mp[b[k]]=0;
				}
				hh=h;
			}
			b[++hh]=a[j];
			mp[a[j]]=hh;
		}
		for(int j=1;j<=hh;j++){
			ans[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

