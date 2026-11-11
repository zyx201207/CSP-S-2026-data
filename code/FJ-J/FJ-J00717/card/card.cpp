#include<bits/stdc++.h>
using namespace std;
int n,m,b[300010];
vector<int> v,a;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	for(int i=1;i<=m;i++){
		int q;
		cin>>q;
		a.push_back(q);
	}
	//1.×¼±¸
	for(int i=1;i<=n;i++){
		while(a.size()!=i-1){
			int p=a[i];
			a.erase(i,&1);
			auto &x=find(v.begin(),v.end(),p);
			if(x!=-1){
				int j=x-v.front();
				while(v.size()!=j){
					a.push_back(v[j]);
					v.erase(j,1);
				}
			}
			v.push_back(p);
		}
		for(int t:v){
			b[t+1]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
