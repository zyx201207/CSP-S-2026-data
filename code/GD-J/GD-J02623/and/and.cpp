#include<bits/stdc++.h>
using namespace std;
vector<int>v[35];
int f[35];
bool b[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	f[0]=1;
	for(int i=1;i<=29;i++)f[i]=f[i-1]*2;
	int n,ans=0,a,m;
	vector<int>q;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		b[i]=1;
		q.push_back(a);
		int u=a;
		for(int j=29;j>=0;j--){
			if(u>=f[j]){
				u-=f[j];
				v[j].push_back(i);
			}
		}
	}
	for(int i=29;i>=0;i--){
		vector<int>p;
		int cnt=0;
		for(int j=0;j<(int)v[i].size();j++){
			if(b[v[i][j]])p.push_back(v[i][j]);
		}
		if(p.size()>=m){
			for(int j=1;j<=n;j++)b[j]=0;
			swap(p,q);
			ans+=f[i];
			for(int j=0;j<(int)q.size();j++){
				b[q[j]]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}
