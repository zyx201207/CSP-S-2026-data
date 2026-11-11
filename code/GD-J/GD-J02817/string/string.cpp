#include <bits/stdc++.h>
using namespace std;
long long ans=0,minn,k1=0,p1=0,p2=0,k2=0,n,a[200005]={0};
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	p1=1,p2=n;
	k1=a[p1];
	k2=a[p2];
	while(p1<p2){
		minn=min(k1,k2);
		if(c[p1]!=c[p2]){
			ans+=minn;
		}
		k1-=minn;
		k2-=minn;
		if(k1<=0){
			p1+=1;
			k1=a[p1];
		}
		if(k2<=0){
			p2-=1;
			k2=a[p2];
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
