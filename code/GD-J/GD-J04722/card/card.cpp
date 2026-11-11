#include <bits/stdc++.h>
using namespace std;
int n,m,cnt,a[500000];

vector<int> v(500000);
map<int,int> mp,ms;
set<int> s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int x=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(s.find(a[j])==s.end()){
				v.push_back(a[j]);
				s.insert(a[j]);
				ms[a[j]]=v.size()-1;
			}else{
				for(int i=ms[a[j]];i<v.size();i++){
					v[i]=0;
					s.erase(v[i]);
					ms.erase(v[i]);
				}
				v.push_back(a[j]);
				s.insert(a[j]);
				ms[a[j]]=v.size()-1;
			}
		}
		for(int j=0;j<v.size();j++) mp[v[j]]++;
		s.clear();
		v.clear();
		ms.clear();
	}
	for(int i=1;i<=m;i++){
		cout<<mp[i]<<" ";
	}
	return 0;
}/*

*/
