#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[500005];
int main(){
	freopen("string.in","r","stdin");
	freopen("string.out","w","stdout");
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	vector<int>x;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			x.push(a[i]);
		}
		for(int j=0;j<x.size();j++){
			ans[x[i]]++;
		}
		for(int j=0;j<x.size();j++){
			for(int k=j+1;k<x.size();k++){
				if(x[j]==x[k]){
					for(int z=jz<=)
				}
			}
		}
	}
	return 0;
}
