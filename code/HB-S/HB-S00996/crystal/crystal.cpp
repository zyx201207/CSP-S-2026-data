#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int n,m,a[MAXN],ans,num;
bool vis[MAXN];
int f(int cnt,int sum){
	for(int i=n;i>=1;--i){
		for(int j=i-1;j>=1;--j){
			sum+=a[i]-a[j];
			if(sum>m){
				sum=0;
				cnt=1;
				break;
			}
			cnt++;
			if(sum==m){
				num=max(num,cnt);
				sum=0;
				cnt=1;
				break;
			}
			else if(sum<m){
				if(num==cnt) num=num;
				else num=max(num,cnt);
			}
		}
	}
	return num;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ans=f(1,0);
	cout<<ans;
	return 0;
}
