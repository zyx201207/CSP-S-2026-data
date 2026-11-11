#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+5,MAXM=5e5+5;
int n,m,a[MAXN],b[MAXN],c[MAXN],d[MAXN],cnt;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int t=1;t<=n;t++){
		int wz=t;cnt=0;
		while(wz<=n){
			d[a[wz]]++;
			int wzx=0;
			for(int j=n;j>=wz;j--)
				if(a[j]==a[wz]){
					wzx=j;
					break;
				}
			wz=wzx+1;
		}
	}for(int i=1;i<=m;i++)cout<<d[i]<<' ';
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1

4 3
1 2 1 3
*/
