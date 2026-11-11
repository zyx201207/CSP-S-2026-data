#include<bits/stdc++.h>
using namespace std;


const int M=3e5+5;
int maxn[M];
vector<int> id[M];
const int N=5e5+5;
int a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		id[a[i]].push_back(i);
	}
	for(int i=1;i<=n;++i){
		int l=i;
		while(l<=n){
			int x=id[a[l]].size();
			if(id[a[l]][x-1]>=l){
				maxn[a[l]]++;
				l=id[a[l]][x-1]+1;
			}
			else{
				l++;
			}
		}
	}
	for(int i=1;i<=m;++i){
		cout<<maxn[i]<<' ';
	}
	return 0;
}
