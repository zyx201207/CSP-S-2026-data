#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],cnt[500005],q[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			bool p=0;
			for(int k=1;k<j;k++){
				if(p==1)q[k]=1;
				if(a[k]==a[j]){
					q[k]=1;
					p=1;
				}
			}
			for(int l=1;l<=n;l++){
				if(q[l]==0){
					cnt[a[l]]++;
				}
				q[l]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" "; 
	}
	return 0;
} 
