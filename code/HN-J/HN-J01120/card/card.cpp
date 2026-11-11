#include <bits/stdc++.h>
using namespace std;
int n,m,a[500001],d[500001],b[500001];
vector<int> v;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		v.clear();
		for(int j=i;j<=n;j++){
			if(!b[a[j]]){
				v.push_back(a[j]);
				b[a[j]]=1;
			}else{
				while(v.back()!=a[j]){
					b[v.back()]=0;
					v.pop_back();
				}
			}
			
		}
		for(int j=0;j<v.size();j++){
			d[v[j]]++;
			b[v[j]]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	return 0;
}

