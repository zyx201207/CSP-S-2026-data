#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

struct node{
	int h;
	int l;
	int r;
};

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m,a[500010]; cin>>n>>m;
	vector<int> v[300010];
	vector<node> p;
	               
	for(int i=0;i<n;i++){
		cin>>a[i];
		for(int j=0;j<(int)v[a[i]].size();j++){
			p.push_back(node{v[a[i]][j],v[a[i]][j],i});
		}
		v[a[i]].push_back(i);
	}
	int cnt[300010]={0};
	for(int i=0;i<n;i++){
		for(int k=max(i-1,0);k<n;k++){
			for(int j=0;j<(int)p.size();j++){
				if(!(p[j].h>=i&&p[j].l<=a[k]&&p[j].r>a[k])){
					cnt[a[k]]++;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	
	return 0;
}
