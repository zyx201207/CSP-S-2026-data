#include<bits/stdc++.h>
using namespace std;
const int N=5e5+3,M=3e5+3;
int n,m;
int a[N];
int vnt[M];
long long ans=0;
vector<int> f(N);
void bt(int j){
	f.clear();
	f.resize(N);
	for(int i=j;i<=n;i++){
		for(int l=0;l<=f.size();l++){
			if(a[i]==f[l]){
				vector<int> tmp;
				for(int ii=0;ii<l;ii++){
					tmp.push_back(f[ii]);
				}
				f.clear();
				f=tmp;
			}
		}
		f.push_back(a[i]);
		
	}
	for(int it:f){
		vnt[it]++;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int tmp;
		cin>>tmp;
		a[i]=tmp;
	}
	for(int i=1;i<=n;i++){
		bt(i);
	}
	for(int i=1;i<=m;i++){
		cout<<vnt[i]<<" ";
	}
	return 0;
}

