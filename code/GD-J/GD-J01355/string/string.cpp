#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[1000008],ans,x,y;
string w[1000008];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>w[i];
	}
	x=1,y=n;
	while(x<=y){
		if(w[x]!=w[y]) ans+=min(a[x],a[y]);
		if(a[x]<a[y]){
			a[y]-=a[x];
			x++;
		}else if(a[x]>a[y]){
			a[x]-=a[y];
			y--;
		}else{
			x++;
			y--;
		}
	}
	cout<<ans;
	return 0;
}
