#include<bits\stdc++.h>
#define t long long
using namespace std;
t n,m,p,a,b,c,i,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a;
		ans=max(a,ans);
	}cout<<ans;
}
