#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int m,n,a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int as=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j!=i){
				int sa=a[i]&a[j];
				as=max(as,sa);
			}
		}
	}
	return 0;
}
