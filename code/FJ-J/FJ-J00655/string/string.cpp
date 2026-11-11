#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200010];
char c[200010];
long long x=1,y,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	y=n;
	while(x<y){
		if(c[x]!=c[y]) ans+=min(a[x],a[y]);	
		if(a[x]<a[y]){
			a[y]-=a[x];
			x++;
		}else{
			a[x]-=a[y];
			y--;
		}
	}cout<<ans;
	return 0;
} 
