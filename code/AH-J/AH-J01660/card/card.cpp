#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5; 
int a[N],b[N],c[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int k=1;k<=n;k++){
		memset(b,0,sizeof b);
		int cnt=0;
		for(int i=k;i<=n;i++){
			int flag=0,k=cnt;
			for(int j=1;j<=k;j++){
				if(flag) cnt--;
				if(b[j]==a[i]) flag=1,cnt--;
			}
			b[++cnt]=a[i];
		}
		for(int i=1;i<=cnt;i++){
			c[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}

