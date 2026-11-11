#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
long long n,m,p[N],a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)p[a[i]]++;
	for(int i=1;i<=m;i++)cout<<p[a[i]]<<" ";
	return 0;
}
