#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int a[500010];
int b[300010];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int sum=i;
		int mj=i;
		for(int j=n;j>mj;j--){
			if(a[mj]==a[j]){
				b[a[mj]]++;
				mj=j+1;
				sum=j+1;
				j=n+1;
				continue;
			}else if(j-1==mj){
				b[a[mj]]++;
				mj++;
				sum++;
				j=n+1;
			}
		}
		for(int z=sum;z<=n;z++){
			b[a[z]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
} 

//10 3
//3 1 2 1 3 2 3 1 2 1
