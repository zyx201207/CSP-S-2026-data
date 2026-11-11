#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> v;
vector<bool> cd(300005);
int n,m,t[500005],a[300005]={};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>t[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(cd[t[j]]==0){
				v.push_back(t[j]);
				cd[t[j]]=1;
			}
			else{
				v.clear();
				cd.resize(0);
			}
		}
		unique(v.begin(),v.end());
		for(int j=0;j<v.size();j++){
			a[v[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<a[i]<<" ";
	}
}
