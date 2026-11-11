#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[500005],b[300005],l,r,c[300005]={0};
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		l=i;
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0)b[a[j]]=j;
			else {
				for(int k=b[a[j]];k<j;k++)b[a[k]]=0;
				b[a[j]]=j,l=j;
			}
		}
		for(int j=l;j<=n;j++)c[a[j]]++;
	}for(int i=1;i<=m;i++)cout<<c[i]<<" ";
	return 0;
} 
