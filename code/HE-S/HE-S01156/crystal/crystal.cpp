#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N], k=1;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	int p=m;
	for(int i=0; i<n; i++){
		if((max(a[i], a[i+1]), a[i+2])-(min(a[i], a[i+1]), a[i+2])<=m/2){
			for(int j=0; j<=m; j++){
				if(a[j]<max(a[j+1], a[j])&&a[j+1]-a[j]<=p/2){
					a[j]++;
					j=0;
					m--;
				}
			}
		}
	}
	for(int i=0; i<n; i++){
		if(a[i]==a[i+1]){
			k++;
		}
	}
	cout<<endl<<k;
	return 0;
}
