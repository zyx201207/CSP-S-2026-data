#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a,f[N][35],ans=0,maxk=0,l[35];//f记录ai的二进制情况,l记录总的二进制每位个数 
vector<int>g[35];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		int k=0;
		while(a){
			if(a&1)
				f[i][k]++,l[k]++;
			a>>=1;
			k++;
		}
		maxk=max(maxk,k-1);
	}
	bool flag=0;
	for(int i=maxk;i>=0;i--){
		if(!flag){
			if(l[i]<m)
				continue;
			for(int j=1;j<=n;j++){
				if(f[j][i])
					g[i].push_back(j);
			}
			flag=1;
			ans+=pow(2,i);
		}
		else{
			int num=0;
			for(int v:g[i+1]){
				if(f[v][i]){
					num++;
					g[i].push_back(v);
				}
			}
			if(num>=m)
				ans+=pow(2,i);
			else{
				g[i].clear();
				for(int v:g[i+1])
					g[i].push_back(v);
			} 
		}
	}
	cout<<ans;
	return 0;
}
