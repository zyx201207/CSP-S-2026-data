#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,m;
struct ff{
	int v,bit[32];
}a[maxn];
vector<int>val[32];
int start;
bool cmp(int x,int y){
	for(int j=start;j>=1;j--)
		if(a[x].bit[j]!=a[y].bit[j])return a[x].bit[j]>a[y].bit[j];
	return 0;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].v;
		int t=a[i].v,idx=0;
		while(t){
			a[i].bit[++idx]=t%2;
			t>>=1;
		}
	}
	for(int j=30;j>=1;j--)for(int i=1;i<=n;i++)
		if(a[i].bit[j])val[j].push_back(i);
	for(int j=30;j>=1;j--){
		if(val[j].size()<m)continue;
		start=j;
		sort(val[j].begin(),val[j].end(),cmp);
		//cout<<j<<"   ";
		//for(int i:val[j])cout<<a[i].v<<' ';
		//cout<<'\n';
		int ans=a[val[j][0]].v;
		for(int i=1;i<m;i++)ans&=a[val[j][i]].v;
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
}
