#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[200001];
	long long ans=0;
	char c[200001];
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	int x=1,y=n,s;
	while(x<y){
		s=min(a[x],a[y]);
		if(c[x]!=c[y]) ans+=s;
		a[x]-=s,a[y]-=s;
		if(a[x]==0) x++;
		else y--;
	}
	cout<<ans;
	return 0;
}
