#include<bits/stdc++.h>
using namespace std;
int n,a[200010],x=1,y,ans;
char c[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;y=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=2*n;i++){
		if(a[x]>a[y]){
			ans+=c[x]==c[y]?0:a[y];
			a[x]-=a[y];
			y--;
		}else if(a[x]<a[y]){
			ans+=c[x]==c[y]?0:a[x];
			a[y]-=a[x];
			x++;
		}else{
			ans+=c[x]==c[y]?0:a[x];
			x++;
			y--;
		}
		if(x>=y){
			break;
		}
	}
	cout<<ans;
	return 0;
}
