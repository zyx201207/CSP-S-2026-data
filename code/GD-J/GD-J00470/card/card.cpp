#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+21;
int n,m;
int a[N];
int t[N];
int d[N],dd[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			d[j]=0;
			dd[j]=0;
		}
		int cnt=0;
		for(int j=i;j<=n;j++){
			if(!d[a[j]]||d[a[j]]>cnt)d[a[j]]=++cnt,dd[cnt]=a[j];
			else cnt=d[a[j]];
		}
		for(int j=1;j<=cnt;j++){
			t[dd[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<t[i]<<" ";
}
