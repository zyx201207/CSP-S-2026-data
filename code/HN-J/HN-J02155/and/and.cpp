#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+10;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans,ans1;
	cin>>n>>m;
	cin>>ans;ans1=ans;
	for(int i=2;i<=n;i++){
		int x;
		cin>>x;
		ans=(ans|x);
		ans1=max(ans,x);
	}
	if(m==1)cout<<ans1;
	else cout<<ans;
	return 0;
}
