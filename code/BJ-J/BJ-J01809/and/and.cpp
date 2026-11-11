#include<bits/stdc++.h>
long long const N=1e5+10;
long long a[N];
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,maxx=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=i;k<m+i;k++)if(j!=k)maxx=max(maxx,a[j]&a[k]);
			}
		}
	cout<<maxx;
	return 0;
}
