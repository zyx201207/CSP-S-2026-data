#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N1=5e5+5,N2=3e5+5;
int n,m;
int a[N2];
vector<int> k;
vector<int> p[N2];
int ans[N2];
bool flag[N2];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		k.clear();
		for(int j=1;j<=m;j++) p[j].clear(),flag[j]=0;
		for(int j=i;j<=n;j++){
			for(int z=p[a[j]].back();z=k.size();z++) k[z]=0;
			for(int z=1;z<=m;z++){
				for(int c=p[z].size();c>=0;c--){
					if(c>=p[a[j]].back()) p[z][p[z].size()-1]=0;
				}
			}
			k.push_back(a[j]);
			p[a[j]].push_back(k.size()-1);
			
		}
		for(auto c:k){
			if(!flag[c]) ans[c]++,flag[c]=1;
		}
	}
	return 0;
}
