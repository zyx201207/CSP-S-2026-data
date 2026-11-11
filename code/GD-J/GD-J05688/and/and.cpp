#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdin);
	int n,m,big=0;
	cin>>n>>m;
	int a[10000000];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	vector<int>b;
	for(int i=0;i<n;i++){
		b[i]=a[i];
	}
	for(int i=2;i<m;i++){
		for(int j=0;j<n;j++){
			for(int k=j;k<n;k++){
				b.insert(b[j]&a[k]);
			}
			b.erase(b[j]);
		}
	}
	for(int i=0;i<b.size();i++){
		if(b[i]>big){
			big=b[i];
		}
	}
	return 0;
}
