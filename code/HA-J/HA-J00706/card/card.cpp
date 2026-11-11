#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
int n,m,a[N],b[N],f[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;for(int i=1;i<=n;i++){cin>>a[i];b[a[i]]=i;}//cout<<b[1]<<b[2]<<b[3];
	for(int i=1;i<=n;i++){int k=1;
		int j=i;while(j<=n){
			f[a[j]]++;j=b[a[j]]+1;
		}
	}
	for(int i=1;i<=m;i++)cout<<f[i]<<" ";
	return 0;
}
