#include <bits/stdc++.h>
using namespace std;
int a[500005],b[300005],r[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];}
	for(int i=0;i<n;i++){
		*r={0};
		int e=0;
		for(int j=0;j<n-i;j++){
			r[e]=a[i+j];
			e++;
			for(int k=0;k<j;k++){
				if(r[j]==r[k]) e=k+1;}}
		for(int j=0;j<e;j++){
			b[r[j]]++;}}
	for(int i=0;i<m;i++){
		cout<<b[i]<<" ";}		
	return 0;
	}
