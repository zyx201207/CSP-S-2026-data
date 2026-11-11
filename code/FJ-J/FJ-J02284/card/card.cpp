#include<bits/stdc++.h>
using namespace std;
int a[200005],st[200005];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		map<int,int>mp;
		for(int j=i;j<=n;j++){
			if(mp[a[j]]==0)mp[a[j]]=j;
			else{
				for(int k=mp[a[j]]+1;k<j;k++)mp[a[k]]=0;
				mp[a[j]]=j;
			} 
		}
		for(int j=1;j<=m;j++)st[j]+=(mp[j]!=0);
//		for(int i=1;i<=m;i++)cout<<st[i]<<" ";
//		cout<<"\n";
	}
	for(int i=1;i<=m;i++)cout<<st[i]<<" ";
	return 0;
} 
