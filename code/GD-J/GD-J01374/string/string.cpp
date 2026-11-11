#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],ans,x,y;
string s=" ";
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	x=1,y=n;
	while(x<y){
		long long minx=min(a[x],a[y]);
		if(c[x]!=c[y]){
			ans+=minx;
		}
		a[x]-=minx,a[y]-=minx;
		if(a[x]==0) x++;
		if(a[y]==0) y--;
	}
	cout<<ans;
	return 0;
}

