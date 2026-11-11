#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200100],cnt[200100];
vector<int>p;
map<long long,long long>k;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			p.push_back(a[j]);
			if(k[a[j]]!=0){
				p.pop_back();
				for(int i1=p.size()-1;i1>=0;i1--){
					if(p[i1]==a[j])break;
					k[a[i1]]=0;
					p.pop_back();
				}
			}
			k[a[j]]=1;
		}
		for(int j=0;j<p.size();j++){
			cnt[p[j]]++;
		}
		k.clear();
		p.clear();
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
} 

