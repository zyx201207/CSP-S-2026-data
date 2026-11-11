#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+5,M=3e5+5;
ll n,m,a[N],ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		ans[a[i]]=i;
	} 
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	return 0;
}
