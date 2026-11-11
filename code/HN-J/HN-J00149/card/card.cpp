#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int maxn=5e5+7;
int a[maxn],ton[maxn],la[maxn],back[maxn];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--) if(!la[a[i]]) la[a[i]]=i;
	for(int i=1;i<=n;i++) back[i]=la[a[i]];
	for(int i=1;i<=n;i++){
		int r=i;
		while(r<=n){
			ton[a[r]]++;
			r=back[r]+1;
		}
	}
	for(int i=1;i<=m;i++) cout<<ton[i]<<" ";
	return 0;
}
