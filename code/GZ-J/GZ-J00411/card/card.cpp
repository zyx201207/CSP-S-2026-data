//GZ-J00411 贵阳市南明区华麟学校 张喆品 
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500020],b[300020],c[300020];
int idx;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(binary_search(b+1,b+idx+1,a[j])){
				for(int i=lower_bound(b+1,b+idx+1,a[j])-b+1;i<=n;i++){
					b[i]=0;
				}
			}
			else{
				idx++;
				b[idx]=a[j];
			}
		}
		for(int i=1;i<=idx;i++){
			c[i]+=binary_search(b+1,b+idx+1,a[i]);
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
	return 0;
}

