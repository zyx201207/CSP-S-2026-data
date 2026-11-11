#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,b[200005],dis[200005],maxx;
void d(int p,int s,int sum){
	if(s==0){
		sum=b[p];
	}if(p<1||p>n||dis[p]==1)return;
	if(s>=m){
		maxx=max(maxx,sum);
		return;
	}sum&=b[p];
	dis[p]=1;
	s++;
	d(p+1,s,sum);d(p-1,s,sum);d(p+2,s,sum);d(p-2,s,sum);
}signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}d(1,0,0);
	cout<<maxx;
	return 0;
}
