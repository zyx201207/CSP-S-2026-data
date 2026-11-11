#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[300006];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int r[300006];
	for(int i=1;i<=m;i++){
		r[i]=0;
	}
	int it=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i-1;j--){
			if(a[i]==a[j]){
				it=i;
			}
		}
		for(int k=it;k<=i;k++){
			r[a[k]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<r[i];
	}
	return 0;
}
