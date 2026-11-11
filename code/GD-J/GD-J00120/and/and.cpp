#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200010],b[40],t,ans;
bool cmp(int x,int y){return (x&((1<<(t+1))-1))>(y&((1<<(t+1))-1));}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<30;j++)
			if(a[i]&(1<<j)) b[j]++;
	}
	for(int i=29;i>=0;i--)
		if(b[i]>=m){
			t=i;
			break;
		}
	sort(a+1,a+n+1,cmp),ans=a[1];
	for(int i=2;i<=m;i++) ans&=a[i];
	cout<<ans;
	return 0;
}/*
3 12 12 15
  11
 101
 110
 110
 111
1111


4 2
3 15 12 12
*/
