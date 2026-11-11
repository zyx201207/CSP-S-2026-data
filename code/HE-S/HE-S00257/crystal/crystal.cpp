#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int n,m,ans=0,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
	scanf("%d",&a[i]);
    }
    for(int i=2;i<=m;i++){
	a[i]=min(a[i],a[i+1]);
	if(ans<m)ans=ans+a[i+1]-a[i];
}cout<<ans/2;
    
	return 0;
}
