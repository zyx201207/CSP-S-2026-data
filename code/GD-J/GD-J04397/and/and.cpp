#include<bits/stdc++.h>
using namespace std;
int n,m,mx,sum,ans;
bool a[200005][30],p[200005];
vector<int>v;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		mx=max(mx,x);
		if(i==1)sum=x;
		else sum&=x;
		for(int j=0;(1<<j)<=x;j++)if((x>>j)&1)a[i][j]=1;
	}
	if(m==1)return cout<<mx,0;
	if(m==n)return cout<<sum,0;
	for(int i=29;i>=0&&v.size()!=m;i--){
		if(v.size()>m){
			vector<int>b;
			for(int j:v)if(a[j][i])b.push_back(j);
			if(v.size()>m&&b.size()>=m){
				for(int j:v)p[j]=0;
				for(int j:b)p[j]=1;
				v=b;
			}
			continue;
		}
		for(int j=1;j<=n&&v.size()<m;j++)
			if(!p[j]&&a[j][i]){
				v.push_back(j);
				p[j]=1;
			}
	}
	for(int i=29;i>=0;i--){
		bool f=1;
		for(int j:v)
			if(!a[j][i]){
				f=0;
				break;
			}
		if(f)ans+=(1<<i);
	}
	cout<<ans;
	return 0;
}
