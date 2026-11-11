#include <bits/stdc++.h>
using namespace std;
long long card[500005],jg[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=0;i<n;++i){
		cin>>card[i];
	}
	for(long long i=0;i<n;++i){
		vector<long long> ing(n+1);
		for(long long j=i;j<n;++j){
			int is=1;
			for(long long k=0;k<ing.size();++k){
				if(ing[k]==card[j]){
					ing.erase(ing.begin()+k,ing.end()-1);
					ing.push_back(card[j]);
					is=0;
				}
			}
			if(is){
				ing.push_back(card[i]);
			}
		}
		for(long long j=0;j<ing.size();++j){
			jg[ing[j]]++;
		}
	}
	for(int i=0;i<m;i++){
		cout<<jg[i]<<" ";
	}
	return 0;
}
