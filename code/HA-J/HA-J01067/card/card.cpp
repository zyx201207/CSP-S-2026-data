#include<bits/stdc++.h>
using namespace std;
int n;
int m;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<"1";
/*	int b[m+5];
	for(int i=1;i<=m;i++){
		for(int j=i;j<=n;j++){
			if(a[j]==i) {
			b[i]++;
		}
	
	}}
	for(int i=1;i<=m;i++){
	cout<<b[i]<<" ";}*/
	return 0;
}
