#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[500005];
int b[500005];
int ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int l=n;
	while(l--){
		for(int i=1;i<=n;i++)b[i]=0;
		int x=0;
		for(int i=n-l;i<=n;i++){
			for(int j=1;j<=x;j++){
				if(a[i]==b[j]){
					b[j]=0;
					for(int k=j;k<=x;k++)b[k]=0;
					break;
				}
			}
			b[++x]=a[i];
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=x;j++){
				if(b[j]==i)ans[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
