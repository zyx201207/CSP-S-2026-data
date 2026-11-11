#include<bits/stdc++.h>
using namespace std;
int n,m,a[200016],b[30],c,d;
bool f(int x,int y){
	return (x&(1<<d))>(y&(1<<d));
}int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int k=0;k<n;k++)for(int j=0;j<30;j++)if(a[k]&(1<<j))b[j]++;
	for(int i=29;i>=0;i--)if(b[i]>=m){
		d=i;c+=(1<<i);sort(a,a+n,f);
		for(int j=0;j<=n;j++)if((a[j]&(1<<d))==0)n=j;
		for(int j=0;j<30;j++)b[j]=0;
		for(int k=0;k<n;k++)for(int j=0;j<30;j++)if(a[k]&(1<<j))b[j]++;
	}cout<<c;
	return 0;
}
