#include<bits/stdc++.h>
using namespace std;
int n,m,a[100000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	bool f=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++){
		for(int j=n;j>0;j--){
			if(a[j]==i){
				cout<<j<<" ";
				break;
			}
		}
	}
	return 0;
}
