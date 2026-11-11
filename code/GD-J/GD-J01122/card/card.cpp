#include <bits/stdc++.h>
using namespace std;
int n,m,a[200009];
int main(){
	freopen("cpp.in","r",stdin);
	freopen("cpp.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i]; 
	}
	for(int i=1;i<=n;i++){
		bool v;
		for(int j=1;j<=n;j++){
			if(table[i]==a[i]){
				v=0;
			}
		}
	}
	return 0;
}
