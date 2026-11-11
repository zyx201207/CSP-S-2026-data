#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000005],d[1000005],t[100005];
map<int,int>mp;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){
		mp.clear();
		for(int j=i;j<=n;j++){
			if(mp[a[j]]!=0){
				for(int k=mp[a[j]]+1;k<=j;k++){
					d[k]=0;
					mp[k]=0;
				}
			}
			mp[a[j]]=j;
			d[j]++;
			
		}
		int ans=0;
		for(int j=1;j<=m;j++){
			t[j]+=d[j];
			d[j]=0;
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
}


