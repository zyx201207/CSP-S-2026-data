#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int a[N],c[N],tong[N],n,m,h;
void solve(int k){
	memset(c,0,sizeof c);
	int pos=0;
	for(int i=k;i<=n;i++){
		for(int j=1;j<=pos;j++){
			if(c[j]==a[i]){
				pos=j-1;
				break;
			}
		}
		pos++;
		c[pos]=a[i];
	}
	for(int i=1;i<=pos;i++){
		tong[c[i]]++;
	}
} 
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		solve(i);
	}
	for(int i=1;i<=m;i++){
		cout<<tong[i]<<" ";
	}
	return 0;
}
