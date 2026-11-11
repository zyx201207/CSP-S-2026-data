#include<bits/stdc++.h>
using namespace std;
long long a[500000+10];
vector<int> v;
long long pm[500000+10];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int z=1;z<=n;z++){
		v.clear();
		for(int i=z;i<=n;i++){
			for(int j=0;j<v.size();j++){
				if(v[j]==a[i]){
					for(int k=j;k<v.size();){
						v.erase(v.begin()+j);
					}
					break;
				}
			}
			v.push_back(a[i]);
		}
		for(int i=0;i<v.size();i++){
			pm[v[i]]++;
			//cout<<v[i]<<" ";
		}
		//cout<<"\n";
	}
	for(int i=1;i<=m;i++){
		cout<<pm[i]<<" ";
	}
	return 0;
}
