#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],v[300005],r,ans;
vector<int>c;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;r=1;
	for(int i=1;i<=n;i++)cin>>a[i];
	while(r<=n){
		while(a[r]==a[r+1])r++;
		r++,ans++;
	}
	cout<<ans;
}
