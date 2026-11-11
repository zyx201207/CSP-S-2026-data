#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int n,m,a[500010],ans[300010],v[300010];
vector<int>nw;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)v[j]=0;
		for(int j=i;j<=n;j++){
			if(v[a[j]]){
				nw.clear();
				for(int j=1;j<=m;j++)v[j]=0;
				nw.pb(a[j]);
				v[a[j]]=1;
			}else{
				nw.pb(a[j]);
				v[a[j]]=1;
			}
		}
		while(!nw.empty()){
			ans[nw.back()]++;
			nw.pop_back();
		}
	}
	for(int i=1;i<=m;i++){
		cout <<ans[i]<<" ";
	}
	return 0;
}
