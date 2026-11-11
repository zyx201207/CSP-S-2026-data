#include<bits/stdc++.h>
using namespace std;
bool A=true;
vector<int> a;
int res[100005];
int alst[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m,ai;
	cin>>n>>m;
	a.push_back(0);
	for(int i=1;i<=n;i++){
		cin>>ai;
		a.push_back(ai);
		alst[ai]=i;
		if(i==1)continue;
		if(ai<a[i-1])A=false;
	}
	if(A){
		for(int i=1;i<=m;i++){
			cout<<alst[i];
			cout<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		vector<int> b(a);
		b.erase(b.begin()+1,b.begin()+i+1);
		for(int j=i;j<=n;j++){
			for(auto it=b.begin()+1;it<b.end();it++){
				if((*it)==a[j]){
					b.erase(it,b.end());
					break;
				}
			}
			b.push_back(a[j]);
		}
		for(long long unsigned j=1;j<b.size();j++){
			res[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<res[i]<<" ";
	}
	return 0;
}
