#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[500005],m[500005],p[500005],cnt;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		m[a[i]]++;
		if(m[a[i]]==2){
			m[a[i]]=0;
			int t=0;
			for(int j=1;j<i;j++){
				if(a[j]==a[i]){
					t=1;
					a[j]=0;
				}
				if(t==1)a[j]=0;
			}
		}
		for(int j=1;j<=i;j++)p[a[j]]++;
	}
	for(int i=1;i<=k;i++){
		cout<<p[i]<<" ";
	}
	return 0;
}
