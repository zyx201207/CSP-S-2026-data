#include<bits/stdc++.h>
using namespace std;
int n,a[200005],a1[200005];
char c[200005],c1[200005];
long long s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		a1[n+1-i]=a[i];
		c1[n+1-i]=c[i];
	}
	int x=1,y=1;
	while(x<=n&&y<=n){
		int m=min(a[x],a1[y]);
		if(c[x]!=c1[y]) s+=m;
		a[x]-=m;
		a1[y]-=m;
		if(a[x]==0) x++;
		if(a1[y]==0) y++;
	}
	cout<<s/2;
	return 0;
}
