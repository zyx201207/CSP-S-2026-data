#include<bits/stdc++.h>
using namespace std;
const int N=5e5+50;
int a[N];
struct IN{int cnt,sum;}k[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],k[a[i]].cnt=i;
	for(int i=1;i<=n;i++){k[a[i]].sum++;if(k[a[i]].cnt==i){k[a[i+1]].sum+=k[a[i]].sum;}}
	for(int i=1;i<=m;i++)cout<<k[i].sum<<' ';
	return 0;
}
