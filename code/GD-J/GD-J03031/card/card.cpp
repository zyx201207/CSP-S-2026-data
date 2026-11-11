#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=500005;
int cnt[N],a[N],n,b[N],m;
int head=1,tail=1;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int x=1;x<=tail;x++){
				if(b[x]==a[j]){
					tail=x;
					break;
				}
			}
			b[tail++]=a[j];
		}
		for(int u=1;u<=tail-1;u++){
			cnt[b[u]]++;
		}
	//	for(int l=1;l<=tail;l++)b[l]=0;
		head=1,tail=1;
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
}
/*


4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1




*/
