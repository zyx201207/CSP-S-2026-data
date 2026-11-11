#include<bits/stdc++.h>
using namespace std;
int num[300005],a[500005],c[500005],vis[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m,r;cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		r=0;
		for(int j=i;j<n;j++){
			//cout<<j<<':'<<a[j]<<"&vis:"<<vis[a[j]]<<' ';
			if(vis[a[j]]) {
				while(r>0 && c[r]!=a[j]){vis[c[r-1]]--;r--;}
				//cout<<'\n'<<r<<'\n';
			}
			c[r]=a[j];r++;vis[a[j]]++;
		}//cout<<'\n';
		for(int j=0;j<r;j++){
			//cout<<c[j]<<' ';
			num[c[j]]++;
		}//cout<<'\n';
		for(int j=1;j<=m;j++)vis[j]=0;
	}
	for(int i=1;i<=m;i++){
		cout<<num[i]<<' ';
	}
}
