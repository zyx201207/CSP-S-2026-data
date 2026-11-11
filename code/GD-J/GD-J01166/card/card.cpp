#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],now[N],tong[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(now,0,sizeof(now));
		int t=0;
		for(int j=i;j<=n;j++){
//			cout<<a[j]<<" "<<t<<" ";
//			for(int c=1;c<=t;c++)
//				cout<<now[c]<<" ";
			for(int k=1;k<=t;k++){
				if(now[k]==a[j]){
					for(int x=k;x<=t;x++)now[x]=0;
					t=k-1;
				}
			}
			t++;
			now[t]=a[j];
		}
		for(int j=1;j<=t;j++){
//			cout<<now[j]<<" ";
			tong[now[j]]++;
		}
//		cout<<endl;
	}
	for(int i=1;i<=m;i++)cout<<tong[i]<<" ";
	return 0;
}
