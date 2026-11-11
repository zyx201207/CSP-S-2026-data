#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int ans=0;
	int n,a;
	cin>>n>>a;
	int b[1000000];
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(b[i]<b[j]){
				ans++;
			}
			if(ans==a){
				cout<<b[i];
			}
		}
	}
	return 0;
}
