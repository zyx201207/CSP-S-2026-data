#include<bits/stdc++.h>
using namespace std;
#define int long long
long long n,m,a[500005],da[500005];vector<int> o[500005];int ji[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
    cin>>n>>m;
    for(int i=1;i<=n;++i){
    	cin>>a[i];
    	o[a[i]].push_back(i);
	}
	for(int i=1;i<=n;++i){
		int j=o[a[i]][o[a[i]].size()-1];
		da[a[i]]++;
		ji[j]++;
		//yi[j]=a[i];
	}
	for(int i=1;i<=500005;++i){
		//cout<<ji[i]<<'l'<<endl;
		if(i>=n)break;
		if(ji[i]){
			int j=o[a[i+1]][o[a[i+1]].size()-1];
			da[a[i+1]]+=ji[i];
			ji[j]+=ji[i]; 
		}
		//if(i==m)break;
	}
	//cout<<m<<"k"; 
	for(int i=1;i<=m;++i){
		cout<<da[i]<<' ';
	} 
	return 0;
} //完了写着写着想发疯了怎么办，早知道就复习线段树了， 没猜错的话这题要用懒标记 
