#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int sp(int x){
	for(int k=0;k<v.size();k++){
		if(v[k]==x){
			return k;
			break;
		}
		if(k==v.size()-1 && v[k]!=x) return -1;
	}
}
int main(){
	freopen(card.in,"r",stdin);
	freopen(card.out,"w",stdout);
	int n,m,a;
	cin>>n>>m;
	int p[500000],sl[300000];
	for(int i=0;i<n;i++){
		cin>>a;
		p[i]=a;
		sl[i]=0;
	}
	for(int i=0;i<n;i++){
		v.clear();
		for(int j=i;j<n;j++){
			v.push_back(p[j]);
			if(sp(p[j])!=-1){
				v.erase(v.begin()+sp(p[j]));
			}
		}
		for(int j=0;j<v.size();j++){
			sl[v[j]]++;
		}
	}
	for(int i=1;i<n;i++){
		cout<<sl[i];
	}
	return 0;
}
