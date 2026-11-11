#include<bits/stdc++.h>
using namespace std;
const int N=2e5+14;
int n,m,ans,a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=29;i>=0;i--){
		int aa=ans+(1<<i),k=0;
		for(int j=1;j<=n;j++)if((aa&a[j])==aa)k++;
		if(k>=m)ans=aa;
	}
	cout<<ans;
	return 0;
}
