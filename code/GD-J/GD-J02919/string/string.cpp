#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,a[1000001];
char ch[1000001];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>ch[i];
	int x=1,y=n;
	while(x<y){
		if(ch[x]!=ch[y])ans+=min(a[x],a[y]);
		int jk=min(a[x],a[y]);
		a[x]-=jk,a[y]-=jk;
		if(a[x]==0) x++;
		if(a[y]==0) y--;
	}
	cout<<ans;
	return 0;
} 
