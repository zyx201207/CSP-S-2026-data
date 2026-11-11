#include<bits/stdc++.h>
//#define int long long
using namespace std;
int n,m,a[500010],lst[300010],tong[300010],bj[500010];
vector<int> path;

void pl(int pos){
	while(path.size()) path.pop_back();
	for(int i=1;i<=m;i++) lst[i]=0;
	for(int i=pos;i<=n;i++){
		if(lst[a[i]]){
			while(path[path.size()-1]!=a[i]){
				lst[path[path.size()-1]]=0;
				path.pop_back();
			}
			path.pop_back();
			lst[a[i]]=i;
		}
		if(!lst[a[i]]) lst[a[i]]=i;
		path.push_back(a[i]); 
	}
	int t=path.size();
	for(int i=0;i<t;i++) tong[path[i]]++;
	return ;
}

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		pl(i);
	}
	for(int i=1;i<=m;i++) cout<<tong[i]<<" ";
	return 0;
} 
