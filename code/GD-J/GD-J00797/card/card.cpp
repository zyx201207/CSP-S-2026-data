#include<iostream>
#include<vector>
using namespace std;
int n,m,a[500005];
long long b[300005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		vector<pair<int,bool>> v;
		for(int j=i;j<=n;j++){
			for(int k=0,sz=v.size();k<sz;k++){
				if(v[k].first==a[j]&&v[k].second){
					for(int l=k;l<sz;l++)v[l].second=0;
					break;
				}
			}
			v.push_back({a[j],1});
		}
		for(int j=0,sz=v.size();j<sz;j++){
			if(v[j].second&&v[j].first<=m)b[v[j].first]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i];
		if(i!=m)cout<<' ';
	} 
	return 0;
} 
