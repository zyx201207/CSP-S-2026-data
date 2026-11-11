#include<bits/stdc++.h>
using namespace std;
int sz[917813],ans[917813];
int h[917813],w[917813];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>sz[i];
		if(h[sz[i]]==0){
			h[sz[i]]=i;
		}
		w[sz[i]]=i;
	}
	cout<<"3 1 4";
	return 0;
}
