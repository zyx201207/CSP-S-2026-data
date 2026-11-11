#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],c[500010];
vector<int>v;
int find(int x){
	for(int i=0;i<v.size();i++){
		if(v[i]==x)return i;
	}return -1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		v.clear();
		for(int j=i;j<=n;j++){
			if(find(a[j])==-1){
				v.push_back(a[j]);
			}else{
				v.erase(v.begin()+find(a[j])+1,v.end());
			}
		}for(int i=0;i<v.size();i++){
			c[v[i]]++;
		}
	}for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
	return 0;
}

