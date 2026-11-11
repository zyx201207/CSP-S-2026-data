#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+5,NN=3e7+5;
struct node{
	int num,need;
} mi[NN];
bool cmp(node a,node b){
	if(a.need==b.need)
	  return a.num<b.num;
	return a.need<b.need;
}
int a[N];
signed main(){
	ios::sync_with_stdio(true);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans=n;
	cin>>n>>m;
	if(n<=5000){
		int now=1;
		for(int i=1;i<=n;i++)
		  cin>>a[i];
		sort(a+1,a+n+1);
		for(int j=2;j<=n;j++){
			int ned=0;
			for(int i=j-1;i>=1;i--){
				ned=ned+(a[j]-a[i]);
				mi[now].num=j-i+1;
				mi[now].need=ned;
				now++;
			}
		}
		sort(mi+1,mi+now,cmp);
		int maxx=INT_MIN;
		for(int i=now-1;i>=1;i--)
		  if(mi[i].need<=m)
			maxx=max(maxx,mi[i].num);
		cout<<maxx<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(i*(i-1)/2>m){
			cout<<i-1<<endl;
			return 0;
		}
	}
	cout<<n;
	return 0;
}
