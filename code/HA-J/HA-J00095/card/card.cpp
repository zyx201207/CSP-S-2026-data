#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[100005];
int tong[100005];
int main(){

	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[n];
	}
	for(int i=1;i<=n;i++){
		if(a[i]>a[i-1]){
			tong[i-1]++;
			tong[i]++;
			
		}
		if(a[i]==a[i-1]){
			for(int i=0;i<n;i++){
				tong[i]=0;
			}
			
		}
		cout<<tong[i];
	}
	
	return 0;
}
