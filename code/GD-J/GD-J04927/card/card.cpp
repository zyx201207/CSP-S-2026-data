#include<bits/stdc++.h> 
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
vector<int>ok;
int b[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=m;j<=n;j++){
			bool as=false;
			for(auto x:ok.size()){
				if(x==a[j]){
					as=true;
				}
			}
			if(as=true){
				for(auto x:ok.size()){
					ok.pop_back(x);
				}
			}
			ok.push_back(a[j]);
		}
		for(int j=0;j<n;j++){
			b[a[j]]++;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
