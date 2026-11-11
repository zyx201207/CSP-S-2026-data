#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0); 
	int n,m;cin>>n>>m;
	vector <int>cnt(m+1);
	for(int i=1;i<=n;i++){
	    cin>>a[i]; 
	}
	for(int i=1;i<=n;i++){
		vector<int>t;
		vector<bool> f(m+1,0);
		for(int j=i;j<=n;j++){
			if(f[a[j]]){
			    t.clear();
			    f.clear();
			}
			t.push_back(a[j]);f[a[j]]=1;
		}
	    for(int k:t){
	    	cnt[k]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
	return 0;
}
