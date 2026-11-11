#include<bits/stdc++.h>
using namespace std;
int n,m,c[500005],cnt[500005];
void moni(int k){
	vector<int> vec;
	for(int i=k;i<=n;++i){
		int pos=-1;
		for(int j=int(vec.size())-1;j>=0;--j){
			if(vec[j]==c[i]){
				pos=j;break;
			}
		}
		if(pos!=-1){
			while(pos!=(int)vec.size()) vec.pop_back();
		}
		vec.push_back(c[i]);
	}
	for(int i=0;i<(int)vec.size();++i){
		++cnt[vec[i]];
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>c[i];
	}
	for(int i=1;i<=n;++i) moni(i);
	for(int i=1;i<=m;++i) cout<<cnt[i]<<" ";
	return 0;
}
