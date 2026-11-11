#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],l[M],ans[M];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		l[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int h=i;
		vector<int> v;
		while(h<n){
			v.push_back(a[h]);
			h=l[a[h]]+1;
		}
		for(long unsigned int j=0;j<v.size();j++) ans[v[j]]++;
	}
	ans[a[n]]=n;
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
}
